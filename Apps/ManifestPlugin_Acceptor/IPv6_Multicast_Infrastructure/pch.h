#ifndef PCH_H
#define PCH_H

#include "framework.h"

#ifdef _WIN32

#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>

#pragma comment (lib, "Ws2_32.lib")
using ssize_t = SSIZE_T;

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#endif

namespace mman
{
   /**
    * Length (in bytes) of a locally stored manifest's digest. Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   constexpr int LocalManifestDigestLenght = 26;

   /**
    * Length (in bytes) of a locally stored UDP - broadcasted message. containing digest/SHA256 hash
    * Is generated outside. Must be updated in case of an external request to change manifest collection inside IC
    */
   constexpr int ManifestMulticastMsgLength = 28;

   /**
    * Length (in bytes) of a locally stored TCP response message with manifest included.
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   constexpr int ManifestResponsetMsgLength = 1777;

   /**
    * Length (in bytes) of a locally stored TCP response message without manifest included.
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   constexpr int EmptyResponsetMsgLength = 26;

   /**
    * Description: Protobuf - wrapped Base64 - encoded local manifest's digest/SHA256 hash represented as a string.
    * Original, not protobuf - encoded digest: "qpPnwsDB6d+2DEj2Rc3xkw=="
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   const char LocalManifestDigest[LocalManifestDigestLenght] =
   {
      0x0a, 0x18, 0x71, 0x70, 0x50, 0x6e, 0x77, 0x73, 0x44, 0x42, 0x36, 0x64,
      0x2b, 0x32, 0x44, 0x45, 0x6a, 0x32, 0x52, 0x63, 0x33, 0x78, 0x6b, 0x77,
      0x3d, 0x3d,
   };

   /**
    * Description: Protobuf - wrapped UDP broadcast (via multicast) message.
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   const char ManifestMulticastMsg[ManifestMulticastMsgLength] =
   {
      0x08, 0x01, 0x12, 0x18, 0x71, 0x70, 0x50, 0x6e, 0x77, 0x73, 0x44, 0x42,
      0x36, 0x64, 0x2b, 0x32, 0x44, 0x45, 0x6a, 0x32, 0x52, 0x63, 0x33, 0x78,
      0x6b, 0x77, 0x3d, 0x3d,
   };

   /**
    * Description: Protobuf - wrapped TCP response message with local manifest included.
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   const char ManifestResponseMsg[ManifestResponsetMsgLength] =
   {
      0x0a, 0x18, 0x71, 0x70, 0x50, 0x6e, 0x77, 0x73, 0x44, 0x42, 0x36, 0x64,
      0x2b, 0x32, 0x44, 0x45, 0x6a, 0x32, 0x52, 0x63, 0x33, 0x78, 0x6b, 0x77,
      0x3d, 0x3d, 0x12, 0xd4, 0x0d, 0x65, 0x79, 0x4a, 0x68, 0x62, 0x47, 0x63,
      0x69, 0x4f, 0x69, 0x41, 0x69, 0x52, 0x56, 0x4d, 0x79, 0x4e, 0x54, 0x59,
      0x69, 0x4c, 0x43, 0x41, 0x69, 0x61, 0x32, 0x6c, 0x6b, 0x49, 0x6a, 0x6f,
      0x67, 0x49, 0x6e, 0x4e, 0x54, 0x54, 0x30, 0x45, 0x75, 0x54, 0x55, 0x56,
      0x43, 0x4c, 0x6d, 0x52, 0x6c, 0x64, 0x69, 0x49, 0x73, 0x49, 0x43, 0x4a,
      0x30, 0x63, 0x79, 0x49, 0x36, 0x49, 0x43, 0x49, 0x79, 0x4d, 0x44, 0x49,
      0x77, 0x4c, 0x54, 0x41, 0x79, 0x4c, 0x54, 0x41, 0x7a, 0x56, 0x44, 0x41,
      0x33, 0x4f, 0x6a, 0x51, 0x31, 0x4f, 0x6a, 0x49, 0x7a, 0x4c, 0x6a, 0x59,
      0x78, 0x4d, 0x44, 0x6b, 0x31, 0x4d, 0x43, 0x4a, 0x39, 0x2e, 0x65, 0x77,
      0x6f, 0x67, 0x49, 0x43, 0x4a, 0x42, 0x63, 0x48, 0x42, 0x73, 0x61, 0x57,
      0x4e, 0x68, 0x64, 0x47, 0x6c, 0x76, 0x62, 0x69, 0x49, 0x36, 0x49, 0x48,
      0x73, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x4a, 0x45, 0x61, 0x57,
      0x64, 0x6c, 0x63, 0x33, 0x52, 0x55, 0x65, 0x58, 0x42, 0x6c, 0x49, 0x6a,
      0x6f, 0x67, 0x49, 0x6c, 0x4e, 0x49, 0x51, 0x53, 0x30, 0x79, 0x4e, 0x54,
      0x59, 0x69, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6b,
      0x52, 0x70, 0x5a, 0x32, 0x56, 0x7a, 0x64, 0x46, 0x5a, 0x68, 0x62, 0x48,
      0x56, 0x6c, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6b, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55,
      0x46, 0x42, 0x51, 0x55, 0x46, 0x42, 0x51, 0x55, 0x45, 0x69, 0x4c, 0x41,
      0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6b, 0x35, 0x68, 0x62, 0x57,
      0x55, 0x69, 0x4f, 0x69, 0x41, 0x69, 0x53, 0x32, 0x39, 0x74, 0x59, 0x6d,
      0x6b, 0x69, 0x43, 0x69, 0x41, 0x67, 0x66, 0x53, 0x77, 0x4b, 0x49, 0x43,
      0x41, 0x69, 0x52, 0x47, 0x39, 0x74, 0x59, 0x57, 0x6c, 0x75, 0x49, 0x6a,
      0x6f, 0x67, 0x65, 0x77, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6b,
      0x52, 0x76, 0x62, 0x57, 0x46, 0x70, 0x62, 0x6b, 0x35, 0x68, 0x62, 0x57,
      0x55, 0x69, 0x4f, 0x69, 0x41, 0x69, 0x4d, 0x44, 0x41, 0x78, 0x4e, 0x43,
      0x49, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x53, 0x56,
      0x42, 0x32, 0x4e, 0x69, 0x49, 0x36, 0x49, 0x46, 0x73, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6d, 0x5a, 0x6b, 0x4e, 0x54,
      0x4d, 0x36, 0x4e, 0x32, 0x4e, 0x69, 0x4f, 0x44, 0x6f, 0x77, 0x4d, 0x7a,
      0x67, 0x7a, 0x4f, 0x6a, 0x41, 0x77, 0x4d, 0x44, 0x4d, 0x36, 0x4d, 0x44,
      0x41, 0x77, 0x4d, 0x44, 0x6f, 0x77, 0x4d, 0x44, 0x41, 0x77, 0x4f, 0x6a,
      0x41, 0x77, 0x4d, 0x44, 0x41, 0x36, 0x4d, 0x44, 0x41, 0x78, 0x4e, 0x43,
      0x49, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x46, 0x30, 0x4b, 0x49, 0x43,
      0x42, 0x39, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43, 0x4a, 0x54, 0x5a, 0x58,
      0x4a, 0x32, 0x5a, 0x58, 0x4a, 0x44, 0x59, 0x58, 0x42, 0x68, 0x59, 0x6d,
      0x6c, 0x73, 0x61, 0x58, 0x52, 0x70, 0x5a, 0x58, 0x4d, 0x69, 0x4f, 0x69,
      0x42, 0x62, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x42, 0x37, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x4a, 0x4f, 0x59, 0x57,
      0x31, 0x6c, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6a, 0x59, 0x77, 0x4e, 0x44,
      0x59, 0x69, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x69, 0x55, 0x48, 0x4a, 0x76, 0x64, 0x47, 0x39, 0x6a, 0x62, 0x32,
      0x77, 0x69, 0x4f, 0x69, 0x41, 0x69, 0x55, 0x30, 0x39, 0x4e, 0x52, 0x55,
      0x6c, 0x51, 0x49, 0x69, 0x77, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x6c, 0x42, 0x76, 0x63, 0x6e, 0x51, 0x69, 0x4f, 0x69,
      0x41, 0x30, 0x4d, 0x6a, 0x67, 0x78, 0x4d, 0x43, 0x77, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c, 0x4e, 0x6c, 0x59, 0x33,
      0x56, 0x79, 0x61, 0x58, 0x52, 0x35, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6b,
      0x35, 0x76, 0x62, 0x6d, 0x55, 0x69, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x42, 0x39, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x65, 0x77,
      0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x54, 0x6d,
      0x46, 0x74, 0x5a, 0x53, 0x49, 0x36, 0x49, 0x43, 0x49, 0x32, 0x4d, 0x44,
      0x49, 0x78, 0x49, 0x69, 0x77, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x6c, 0x42, 0x79, 0x62, 0x33, 0x52, 0x76, 0x59, 0x32,
      0x39, 0x73, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6c, 0x4e, 0x50, 0x54, 0x55,
      0x56, 0x4a, 0x55, 0x43, 0x49, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x4a, 0x51, 0x62, 0x33, 0x4a, 0x30, 0x49, 0x6a,
      0x6f, 0x67, 0x4e, 0x44, 0x49, 0x34, 0x4d, 0x54, 0x51, 0x73, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x4a, 0x54, 0x5a, 0x57,
      0x4e, 0x31, 0x63, 0x6d, 0x6c, 0x30, 0x65, 0x53, 0x49, 0x36, 0x49, 0x43,
      0x4a, 0x4f, 0x62, 0x32, 0x35, 0x6c, 0x49, 0x67, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x66, 0x53, 0x77, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x48,
      0x73, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6b,
      0x35, 0x68, 0x62, 0x57, 0x55, 0x69, 0x4f, 0x69, 0x41, 0x69, 0x4e, 0x6a,
      0x41, 0x7a, 0x4e, 0x53, 0x49, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x4a, 0x51, 0x63, 0x6d, 0x39, 0x30, 0x62, 0x32,
      0x4e, 0x76, 0x62, 0x43, 0x49, 0x36, 0x49, 0x43, 0x4a, 0x54, 0x54, 0x30,
      0x31, 0x46, 0x53, 0x56, 0x41, 0x69, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x55, 0x47, 0x39, 0x79, 0x64, 0x43,
      0x49, 0x36, 0x49, 0x44, 0x51, 0x79, 0x4f, 0x44, 0x45, 0x77, 0x4c, 0x41,
      0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x55, 0x32,
      0x56, 0x6a, 0x64, 0x58, 0x4a, 0x70, 0x64, 0x48, 0x6b, 0x69, 0x4f, 0x69,
      0x41, 0x69, 0x54, 0x6d, 0x39, 0x75, 0x5a, 0x53, 0x49, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x48, 0x30, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x42, 0x37, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x4a, 0x4f, 0x59, 0x57, 0x31, 0x6c, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6a,
      0x59, 0x77, 0x4d, 0x7a, 0x51, 0x69, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x55, 0x48, 0x4a, 0x76, 0x64, 0x47,
      0x39, 0x6a, 0x62, 0x32, 0x77, 0x69, 0x4f, 0x69, 0x41, 0x69, 0x55, 0x30,
      0x39, 0x4e, 0x52, 0x55, 0x6c, 0x51, 0x49, 0x69, 0x77, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c, 0x42, 0x76, 0x63, 0x6e,
      0x51, 0x69, 0x4f, 0x69, 0x41, 0x30, 0x4d, 0x6a, 0x67, 0x78, 0x4e, 0x43,
      0x77, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c,
      0x4e, 0x6c, 0x59, 0x33, 0x56, 0x79, 0x61, 0x58, 0x52, 0x35, 0x49, 0x6a,
      0x6f, 0x67, 0x49, 0x6b, 0x35, 0x76, 0x62, 0x6d, 0x55, 0x69, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x42, 0x39, 0x4c, 0x41, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x65, 0x77, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x69, 0x54, 0x6d, 0x46, 0x74, 0x5a, 0x53, 0x49, 0x36, 0x49, 0x43,
      0x49, 0x32, 0x4d, 0x44, 0x42, 0x6c, 0x49, 0x69, 0x77, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c, 0x42, 0x79, 0x62, 0x33,
      0x52, 0x76, 0x59, 0x32, 0x39, 0x73, 0x49, 0x6a, 0x6f, 0x67, 0x49, 0x6c,
      0x4e, 0x50, 0x54, 0x55, 0x56, 0x4a, 0x55, 0x43, 0x49, 0x73, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x4a, 0x51, 0x62, 0x33,
      0x4a, 0x30, 0x49, 0x6a, 0x6f, 0x67, 0x4e, 0x44, 0x49, 0x34, 0x4d, 0x54,
      0x41, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x4a, 0x54, 0x5a, 0x57, 0x4e, 0x31, 0x63, 0x6d, 0x6c, 0x30, 0x65, 0x53,
      0x49, 0x36, 0x49, 0x43, 0x4a, 0x4f, 0x62, 0x32, 0x35, 0x6c, 0x49, 0x67,
      0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x66, 0x51, 0x6f, 0x67, 0x49, 0x46,
      0x30, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x6b, 0x4e, 0x73, 0x61, 0x57,
      0x56, 0x75, 0x64, 0x45, 0x4e, 0x68, 0x63, 0x47, 0x46, 0x69, 0x61, 0x57,
      0x78, 0x70, 0x64, 0x47, 0x6c, 0x6c, 0x63, 0x79, 0x49, 0x36, 0x49, 0x46,
      0x73, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x48, 0x73, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c, 0x4e, 0x50, 0x54, 0x55,
      0x56, 0x4a, 0x55, 0x43, 0x4d, 0x32, 0x4d, 0x44, 0x41, 0x35, 0x49, 0x6a,
      0x6f, 0x67, 0x57, 0x77, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x4a, 0x68, 0x62, 0x47, 0x77, 0x69, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x46, 0x30, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x48, 0x30, 0x73, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x42, 0x37, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x4a, 0x54, 0x54, 0x30, 0x31, 0x46, 0x53, 0x56, 0x41, 0x6a, 0x4e, 0x6a,
      0x41, 0x77, 0x59, 0x53, 0x49, 0x36, 0x49, 0x46, 0x73, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x59, 0x57,
      0x78, 0x73, 0x49, 0x67, 0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x42, 0x64, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x42, 0x39, 0x4c, 0x41,
      0x6f, 0x67, 0x49, 0x43, 0x41, 0x67, 0x65, 0x77, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x69, 0x55, 0x30, 0x39, 0x4e, 0x52, 0x55,
      0x6c, 0x51, 0x49, 0x7a, 0x59, 0x77, 0x4d, 0x54, 0x63, 0x69, 0x4f, 0x69,
      0x42, 0x62, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x6d, 0x46, 0x73, 0x62, 0x43, 0x49, 0x4b, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x58, 0x51, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x66, 0x53, 0x77, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x48,
      0x73, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x6c,
      0x4e, 0x50, 0x54, 0x55, 0x56, 0x4a, 0x55, 0x43, 0x4d, 0x32, 0x4d, 0x44,
      0x59, 0x34, 0x49, 0x6a, 0x6f, 0x67, 0x57, 0x77, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x4a, 0x68, 0x62, 0x47,
      0x77, 0x69, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x46,
      0x30, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x48, 0x30, 0x73, 0x43, 0x69,
      0x41, 0x67, 0x49, 0x43, 0x42, 0x37, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x4a, 0x54, 0x54, 0x30, 0x31, 0x46, 0x53, 0x56,
      0x41, 0x6a, 0x4e, 0x6a, 0x41, 0x32, 0x4f, 0x53, 0x49, 0x36, 0x49, 0x46,
      0x73, 0x4b, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43, 0x41, 0x67, 0x49, 0x43,
      0x41, 0x69, 0x59, 0x57, 0x78, 0x73, 0x49, 0x67, 0x6f, 0x67, 0x49, 0x43,
      0x41, 0x67, 0x49, 0x43, 0x42, 0x64, 0x43, 0x69, 0x41, 0x67, 0x49, 0x43,
      0x42, 0x39, 0x43, 0x69, 0x41, 0x67, 0x58, 0x51, 0x70, 0x39, 0x2e, 0x63,
      0x77, 0x44, 0x68, 0x4e, 0x39, 0x50, 0x48, 0x61, 0x78, 0x7a, 0x32, 0x4e,
      0x6d, 0x30, 0x77, 0x6b, 0x63, 0x59, 0x56, 0x56, 0x55, 0x37, 0x44, 0x6d,
      0x50, 0x37, 0x78, 0x37, 0x42, 0x78, 0x34, 0x42, 0x74, 0x59, 0x4c, 0x34,
      0x7a, 0x6a, 0x51, 0x34, 0x44, 0x77, 0x55, 0x2d, 0x33, 0x42, 0x6f, 0x39,
      0x61, 0x4d, 0x53, 0x6c, 0x6e, 0x5f, 0x31, 0x42, 0x6d, 0x53, 0x4b, 0x30,
      0x4b, 0x62, 0x4f, 0x69, 0x70, 0x76, 0x4b, 0x34, 0x42, 0x36, 0x5a, 0x61,
      0x73, 0x35, 0x37, 0x59, 0x4d, 0x57, 0x5f, 0x74, 0x7a, 0x6f, 0x77, 0x59,
      0x77,
   };

   /**
    * Description: Protobuf - wrapped TCP response message without local manifest included.
    * Is generated outside.
    * Must be updated in case of an external request to change manifest collection inside IC
    */
   const char ManifestEmptyResponseMsg[EmptyResponsetMsgLength] =
   {
      0x0a, 0x18, 0x71, 0x70, 0x50, 0x6e, 0x77, 0x73, 0x44, 0x42, 0x36, 0x64,
      0x2b, 0x32, 0x44, 0x45, 0x6a, 0x32, 0x52, 0x63, 0x33, 0x78, 0x6b, 0x77,
      0x3d, 0x3d,
   };
}

#endif //PCH_H
