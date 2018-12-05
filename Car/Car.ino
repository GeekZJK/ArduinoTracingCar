/*
   White 0
   Black 1
*/

//debugging parameter
#define LOWSPEED 8
#define HIGHSPEED 15

bool car_switch;
bool L_flag;

enum turn_type {LEFT, RIGHT, FORWARD, BACKWARD};
enum map_type {IS, L, Y, LOST, WALL};
enum line_type {WHITE, BLACK};

struct
{
  bool Middle;
  bool Wall;
  bool Left;
  bool Right;
} IRSensor;

//IO config
#define pinMSensor A3      //pin A5
#define pinWSensor A2     //pin A3
#define pinLSensor A4      //pin A5
#define pinRSensor A1     //pin A3


#define pinLQ3 3              //pin D3
#define pinLQ2 4              //pin D4
#define pinLQ1 5              //pin D5
#define pinLQ0 6              //pin D6

#define pinRQ3 7              //pin D7
#define pinRQ2 8              //pin D8
#define pinRQ1 9              //pin D9
#define pinRQ0 10             //pin D10

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

//define variables to be used in script

void motor_left (int s)
{
  switch (s)
  {
    case  0:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, LOW );
      break;

    case  1:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, HIGH );
      break;

    case  2:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, LOW );
      break;

    case  3:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, HIGH);
      break;

    case  4:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, HIGH );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, LOW );
      break;

    case  5:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, LOW );
      break;

    case  6:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, HIGH );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, LOW );
      break;

    case  7:
      digitalWrite(pinLQ3, LOW );
      digitalWrite(pinLQ2, HIGH );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, HIGH );
      break;

    case  8:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, LOW);
      break;

    case  9:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, HIGH );
      break;

    case  10:
      digitalWrite(pinLQ3, HIGH);
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, HIGH);
      digitalWrite(pinLQ0, LOW );
      break;

    case  11:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, LOW );
      digitalWrite(pinLQ1, HIGH );
      digitalWrite(pinLQ0, HIGH );
      break;

    case  12:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, HIGH);
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, LOW );
      break;

    case  13:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, HIGH );
      digitalWrite(pinLQ1, LOW );
      digitalWrite(pinLQ0, HIGH);
      break;

    case  14:
      digitalWrite(pinLQ3, HIGH );
      digitalWrite(pinLQ2, HIGH);
      digitalWrite(pinLQ1, HIGH);
      digitalWrite(pinLQ0, LOW );
      break;

    case  15:
      digitalWrite(pinLQ3, HIGH);
      digitalWrite(pinLQ2, HIGH);
      digitalWrite(pinLQ1, HIGH);
      digitalWrite(pinLQ0, HIGH );
      break;
  }
}

void motor_right (int s)
{
  switch (s)
  {
    case  0:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, LOW );
      break;

    case  1:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, HIGH );
      break;

    case  2:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, LOW );
      break;

    case  3:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, HIGH);
      break;

    case  4:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, HIGH );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, LOW );
      break;

    case  5:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, LOW );
      break;

    case  6:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, HIGH );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, LOW );
      break;

    case  7:
      digitalWrite(pinRQ3, LOW );
      digitalWrite(pinRQ2, HIGH );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, HIGH );
      break;

    case  8:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, LOW);
      break;

    case  9:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, HIGH );
      break;

    case  10:
      digitalWrite(pinRQ3, HIGH);
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, HIGH);
      digitalWrite(pinRQ0, LOW );
      break;

    case  11:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, LOW );
      digitalWrite(pinRQ1, HIGH );
      digitalWrite(pinRQ0, HIGH );
      break;

    case  12:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, HIGH);
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, LOW );
      break;

    case  13:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, HIGH );
      digitalWrite(pinRQ1, LOW );
      digitalWrite(pinRQ0, HIGH);
      break;

    case  14:
      digitalWrite(pinRQ3, HIGH );
      digitalWrite(pinRQ2, HIGH);
      digitalWrite(pinRQ1, HIGH);
      digitalWrite(pinRQ0, LOW );
      break;

    case  15:
      digitalWrite(pinRQ3, HIGH);
      digitalWrite(pinRQ2, HIGH);
      digitalWrite(pinRQ1, HIGH);
      digitalWrite(pinRQ0, HIGH );
      break;
  }
}

void change_dir (int d)
{
  switch (d)
  {
    case FORWARD:
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      break;

    case BACKWARD:
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, LOW);
      break;

    case LEFT:
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      break;

    case RIGHT:
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      break;
  }
}

void car_stop()
{
  motor_left(0);
  motor_right(0);
}

void car_move_IS ()
{
  change_dir (FORWARD);
  motor_left (HIGHSPEED);
  motor_right (HIGHSPEED);
  get_sensor_data();

  while (IRSensor.Left == WHITE && IRSensor.Right == BLACK)
  {
    change_dir(LEFT);
    motor_left (HIGHSPEED);
    motor_right (HIGHSPEED);
    get_sensor_data();
    if (IRSensor.Middle == WHITE)
    {
      break;
    }
  }

  while (IRSensor.Left == BLACK && IRSensor.Right == WHITE)
  {
    change_dir(RIGHT);
    motor_left (HIGHSPEED);
    motor_right (HIGHSPEED);
    get_sensor_data();
    if (IRSensor.Middle == WHITE)
    {
      break;
    }
  }
}

void car_move_L ()
{
  change_dir (FORWARD);
  motor_left (HIGHSPEED);
  motor_right (HIGHSPEED);
  get_sensor_data();

  while (IRSensor.Left == WHITE && IRSensor.Right == BLACK)
  {
    change_dir(LEFT);
    motor_left (LOWSPEED);
    motor_right (HIGHSPEED);
    get_sensor_data();
  }

  while (IRSensor.Left == BLACK && IRSensor.Right == WHITE)
  {
    change_dir(RIGHT);
    motor_left (HIGHSPEED);
    motor_right (LOWSPEED);
    get_sensor_data();
  }
}

void car_lost ()
{
  delay(1000);
  get_sensor_data();
  if (map_detect() == LOST)
  {
    car_stop();
  }
}

void car_move_Y ()
{
  static int Y_count = 1;

  if (Y_count == 1 || Y_count == 2)
  {
    do
    {
      change_dir (LEFT);
      motor_left (HIGHSPEED);
      motor_right (HIGHSPEED);
      get_sensor_data();
    }
    //while (IRSensor.Left == WHITE || IRSensor.Right == WHITE);
    while (IRSensor.Middle == BLACK);
    L_flag = true;
  }

  if (Y_count == 3)
  {
    do
    {
      change_dir (RIGHT);
      motor_left (HIGHSPEED);
      motor_right (HIGHSPEED);
      get_sensor_data();
    }
    //while (IRSensor.Left == WHITE || IRSensor.Right == WHITE);
    while (IRSensor.Middle == BLACK);
  }

  Y_count++;
}

void car_move_wall ()
{
  change_dir (BACKWARD);
  motor_left (LOWSPEED);
  motor_right (LOWSPEED);
  delay(2000);
  car_stop();
  car_switch = false;
}

void get_sensor_data ()
{
  IRSensor.Middle = digitalRead(pinMSensor);
  IRSensor.Wall = digitalRead(pinWSensor);
  IRSensor.Left = digitalRead(pinLSensor);
  IRSensor.Right = digitalRead(pinRSensor);
}

int map_detect()
{
  int type = -1;

  get_sensor_data();

  if (IRSensor.Left == WHITE && IRSensor.Middle == BLACK && IRSensor.Right == WHITE)
  {
    type = Y;
  }
  else if (IRSensor.Left == BLACK && IRSensor.Middle == BLACK && IRSensor.Right == BLACK)
  {
    type = LOST;
  }
  else if (IRSensor.Wall == WHITE)
  {
    type = WALL;
  }
  else
  {
    if (L_flag)
    {
      type = L;
    }
    else
    {
      type = IS;
    }
  }
  return type;
}

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(pinMSensor, INPUT);
  pinMode(pinWSensor, INPUT);
  pinMode(pinLSensor, INPUT);
  pinMode(pinRSensor, INPUT);

  pinMode(pinLQ3, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ0, OUTPUT);

  pinMode(pinRQ3, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ0, OUTPUT);

  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);

  car_switch = false;
  L_flag = false;

  change_dir (FORWARD);
  car_stop();

  do
  {
    get_sensor_data();
  }
  while (IRSensor.Wall == BLACK);
  car_switch = true;
  delay(500);
}

// the loop function runs over and over again forever
void loop() {

  if (car_switch)
  {
    switch (map_detect())
    {
      case IS:
        car_move_IS();
        break;

      case L:
        car_move_L();
        break;

      case Y:
        car_move_Y();
        break;
      /*
          case LOST:
            car_lost();
            break;
      */
      case WALL:
        car_move_wall();
        break;

      default:
        car_move_IS();
        break;
    }
  }
}
