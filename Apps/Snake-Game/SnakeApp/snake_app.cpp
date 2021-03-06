/**
 * SnakeApp
 */
#include "snake_app.hpp"

void change_direction()
{
   // Считываем нажатую клавишу с помощью функции getch().
   symbol = _getch();
   switch (symbol)
   {
   case 'w': // Вверх
      if (change_x != 1 || change_y != 0)
      {
         change_x = -1;
         change_y = 0;
      }
      break;
   case 'a': // Влево
      if (change_x != 0 || change_y != 1)
      {
         change_x = 0;
         change_y = -1;
      }
      break;
   case 's': // Вниз
      if (change_x != -1 || change_y != 0)
      {
         change_x = 1;
         change_y = 0;
      }
      break;
   case 'd': // Вправо
      if (change_x != 0 || change_y != -1)
      {
         change_x = 0;
         change_y = 1;
      }
      break;
#ifdef WINDOWS
   case 'q':
      nonblock(NB_DISABLE);
      std::exit(0);
      break;
#endif
   default:
      break;
   }
}

void show_table()
{
   // Очищаем консоль.
#ifdef WINDOWS
   system("cls");
#else
   system("clear");
#endif

   // Выводим таблицу и края.
   for (int i = 0; i <= N + 1; ++i)
   {
      for (int j = 0; j <= M + 1; ++j)
      {
         std::cout << (i == 0 || j == 0 || i == N + 1 || j == M + 1
                          ? '#'
                          : a[i][j])
            << (j <= M ? "" : "\n");
      }
   }
}

void clear_snake_on_table()
{
   for (int i = 1; i <= snake_size; ++i)
   {
      a[coords_x[i]][coords_y[i]] = ' ';
   }
}

/**
 * \brief Красим координаты змейки
 */
void show_snake_on_table()
{
   // Изменяем тип головы
   if (change_x == 1 && change_y == 0)
   {
      a[coords_x[1]][coords_y[1]] = 'v';
   }

   if (change_x == -1 && change_y == 0)
   {
      a[coords_x[1]][coords_y[1]] = '^';
   }

   if (change_x == 0 && change_y == 1)
   {
      a[coords_x[1]][coords_y[1]] = '>';
   }

   if (change_x == 0 && change_y == -1)
   {
      a[coords_x[1]][coords_y[1]] = '<';
   }

   // Красим змейку
   for (int i = 2; i <= snake_size; ++i)
   {
      a[coords_x[i]][coords_y[i]] = '@';
   }
}

/**
 * \brief Проверяем, съела ли змейка саму себя
 * \return true если змейка съела саму себя, false - в противном случае
 */
bool game_over()
{
   bool eatHerself = false;

   for (int i = 2; i <= snake_size; ++i)
   {
      // Если координаты головы змейки равны координате какой-либо части тела,
      // змейки, то змейка съела саму себя
      if (coords_x[1] == coords_x[i] && coords_y[1] == coords_y[i])
      {
         eatHerself = true;
         break;
      }
   }

   return eatHerself;
}

/**
 * \brief Проверяем, не вышла ли змейка за поле, если да, то возвращаем её обратно
 */
void check_coordinates()
{
   if (coords_x[1] > N)
   {
      coords_x[1] = 1;
   }

   if (coords_x[1] < 1)
   {
      coords_x[1] = N;
   }

   if (coords_y[1] > M)
   {
      coords_y[1] = 1;
   }

   if (coords_y[1] < 1)
   {
      coords_y[1] = M;
   }
}

/**
 * \brief Функция следующего хода, в которой наша змейка сдвигается в сторону на одну ячейку
 */
void next_step()
{
   // Чистим таблицу от змейки
   clear_snake_on_table();

   // Передвигаем тело змейки
   for (int i = snake_size; i >= 2; --i)
   {
      coords_x[i] = coords_x[i - 1];
      coords_y[i] = coords_y[i - 1];
   }

   // Передвигаем голову змейки
   coords_x[1] += change_x;
   coords_y[1] += change_y;

   // Проверяем, в порядке ли координаты
   check_coordinates();

   // Если голова змейки там же, где и еда, то увеличиваем размер змейки
   // и очищаем координаты змейки
   if (coords_x[1] == food_x && coords_y[1] == food_y)
   {
      snake_size++;
      food_x = -1;
      food_y = -1;
   }

   // Рисуем змейку
   show_snake_on_table();

   // Если змейка укусила себя
   if (game_over())
   {
      // Сообщаем всю правду об игроке
      std::cout << "You're looser!\n";
      // Приостанавливаем игру
#ifdef WIN32
      system("pause");
#endif
      // Завершаем программу
      std::exit(EXIT_SUCCESS);
   }
}

/**
 * \brief Функция проверки на наличие еды на карте
 * \return true, если еда есть, false в противном случае
 */
bool food_check()
{
   // Если координаты еды неопределенны, то возвращаем true
   return food_x == -1 && food_y == -1 ? false : true;
}

/**
 * \brief Функция добавления еды на карту
 */
void place_food()
{
   std::srand(std::time(nullptr));
   // Ставим в рандомное место еду.
   for (int i = 1; i <= 9; ++i)
   {
      int x = std::rand();
      int y = std::rand();
      if (x < 0)
      {
         x *= -1;
      }

      if (y < 0)
      {
         y *= -1;
      }

      x %= (N + 1);
      y %= (M + 1);
      if (x == 0)
      {
         ++x;
      }

      if (y == 0)
      {
         ++y;
      }

      if (a[x][y] != '@' && a[x][y] != 'v' && a[x][y] != '^' && a[x][y] != '<' && a[x][y] != '>')
      {
         food_x = x;
         food_y = y;
         a[x][y] = '+';
         return;
      }
   }
}

/**
 * \brief Начальные установки
 */
void standart_settings()
{
   // Размер змеи - 2.
   snake_size = 2;

   // Змейка занимает две клетки вправо от координаты {1,1}
   coords_x[1] = 1;
   coords_y[1] = 2;
   coords_x[2] = 1;
   coords_y[2] = 1;

   // Змейка движется вправо
   change_x = 0;
   change_y = 1;
}
