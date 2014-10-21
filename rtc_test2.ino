#include <Wire.h>
#include <EEPROM.h>

int addr = 0;
const int DS1307 = 0x68; // Address of DS1307 see data sheets
const char* days[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] =
{"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
 
// Initializes all values: 
byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;

byte task1HourS = 0;
byte task1MinS = 0;
byte task1SecS = 0;
byte task1HourE = 0;
byte task1MinE = 0;
byte task1SecE = 0;

byte task2HourS = 0;
byte task2MinS = 0;
byte task2SecS = 0;
byte task2HourE = 0;
byte task2MinE = 0;
byte task2SecE = 0;

byte task3HourS = 0;
byte task3MinS = 0;
byte task3SecS = 0;
byte task3HourE = 0;
byte task3MinE = 0;
byte task3SecE = 0;

byte task1HourS_Stored, task1MinS_Stored, task1SecS_Stored, task1HourE_Stored, task1MinE_Stored, task1SecE_Stored;
byte task2HourS_Stored, task2MinS_Stored, task2SecS_Stored, task2HourE_Stored, task2MinE_Stored, task2SecE_Stored;
byte task3HourS_Stored, task3MinS_Stored, task3SecS_Stored, task3HourE_Stored, task3MinE_Stored, task3SecE_Stored;


void setup() {
  Wire.begin();
  Serial.begin(9600);
  delay(2000); // This delay allows the MCU to read the current date and time.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
  
  delay(1000);
  int setting_time=0;
  
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  setting_time = digitalRead(11); 
  
 
  
  if (setting_time==HIGH){
  
  Serial.print("The current date and time is: ");
  printTime();
  Serial.println("Please change to newline ending the settings on the lower right of the Serial Monitor");
  Serial.println("Would you like to set the date and time now? Y/N");
 
  while (!Serial.available()) delay(10);
  if (Serial.read() == 'y' || Serial.read() == 'Y')
 
  // This set of functions allows the user to change the date and time
  {
    Serial.read();
    setTime();
    Serial.print("The current date and time is now: ");
    printTime();
  }
 
 
  Serial.println("Thank you.");
  
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  
  
  
  Serial.println("Would you like to set the time for Tasks? Y/N");
  
  while (!Serial.available()) delay(10);
  if (Serial.read() == 'y' || Serial.read() == 'Y')
 
  // This set of functions allows the user to change the date and time
  {
    Serial.read();
    Serial.print("Enter task1 Start Time\n");
    
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task1HourS = readByte();
    EEPROM.write(addr, task1HourS);
    addr = addr+1;
    Serial.println(task1HourS);    
    Serial.print("Enter Min: ");
    task1MinS = readByte();
    EEPROM.write(addr, task1MinS);
    addr = addr+1;
    Serial.println(task1MinS);
    Serial.print("Enter Sec: ");
    task1SecS = readByte();
    EEPROM.write(addr, task1SecS);
    addr = addr+1;
    Serial.println(task1SecS);
    
    Serial.print("Enter task1 Stop Time\n ");
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task1HourE = readByte();
    EEPROM.write(addr, task1HourE);
    addr = addr+1;
    Serial.println(task1HourE);    
    Serial.print("Enter Min: ");
    task1MinE = readByte();
    EEPROM.write(addr, task1MinE);
    addr = addr+1;
    Serial.println(task1MinE);
    Serial.print("Enter Sec: ");
    task1SecE = readByte();
    EEPROM.write(addr, task1SecE);
    addr = addr+1;
    Serial.println(task1SecE);
    
    
    Serial.print("Enter task2 Start Time\n ");
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task2HourS = readByte();
    EEPROM.write(addr, task2HourS);
    addr = addr+1;
    Serial.println(task2HourS);    
    Serial.print("Enter Min: ");
    task2MinS = readByte();
    EEPROM.write(addr, task2MinS);
    addr = addr+1;
    Serial.println(task2MinS);
    Serial.print("Enter Sec: ");
    task2SecS = readByte();
    EEPROM.write(addr, task2SecS);
    addr = addr+1;
    Serial.println(task2SecS);
    
    Serial.print("Enter task2 Stop Time\n ");
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task2HourE = readByte();
    EEPROM.write(addr, task2HourE );
    addr = addr+1;
    Serial.println(task2HourE);    
    Serial.print("Enter Min: ");
    task2MinE = readByte();
    EEPROM.write(addr, task2MinE);
    addr = addr+1;
    Serial.println(task2MinE);
    Serial.print("Enter Sec: ");
    task2SecE = readByte();
    EEPROM.write(addr, task2SecE );
    addr = addr+1;
    Serial.println(task2SecE);
    
    
    Serial.print("Enter task3 Start Time \n");
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task3HourS = readByte();
    EEPROM.write(addr, task3HourS);
    addr = addr+1;
    Serial.println(task3HourS);    
    Serial.print("Enter Min: ");
    task3MinS = readByte();
    EEPROM.write(addr, task3MinS);
    addr = addr+1;
    Serial.println(task3MinS);
    Serial.print("Enter Sec: ");
    task3SecS = readByte();
    EEPROM.write(addr, task3SecS);
    addr = addr+1;
    Serial.println(task3SecS);
    
    Serial.print("Enter task3 Stop Time \n");
    Serial.println("**********************");
    Serial.print("Enter Hour: ");    
    task3HourE = readByte();
    EEPROM.write(addr, task3HourE);
    addr = addr+1;
    Serial.println(task3HourE);    
    Serial.print("Enter Min: ");
    task3MinE = readByte();
    EEPROM.write(addr, task3MinE);
    addr = addr+1;
    Serial.println(task3MinE);
    Serial.print("Enter Sec: ");
    task3SecE = readByte();
    EEPROM.write(addr, task3SecE);
    addr = addr+1;
    Serial.println(task3SecE);
    
    
    
    
    
     
  }
 
  Serial.println("Have a nice day!!!");
  }
  
  int address = 0;
  task1HourS_Stored=EEPROM.read(address); address = address +1;
  task1MinS_Stored=EEPROM.read(address); address = address +1;
  task1SecS_Stored=EEPROM.read(address); address = address +1;
  task1HourE_Stored=EEPROM.read(address); address = address +1;
  task1MinE_Stored=EEPROM.read(address); address = address +1;
  task1SecE_Stored=EEPROM.read(address); address = address +1;
  
  task2HourS_Stored=EEPROM.read(address); address = address +1;
  task2MinS_Stored=EEPROM.read(address); address = address +1;
  task2SecS_Stored=EEPROM.read(address); address = address +1;
  task2HourE_Stored=EEPROM.read(address); address = address +1;
  task2MinE_Stored=EEPROM.read(address); address = address +1;
  task2SecE_Stored=EEPROM.read(address); address = address +1;
  
  task3HourS_Stored=EEPROM.read(address); address = address +1;
  task3MinS_Stored=EEPROM.read(address); address = address +1;
  task3SecS_Stored=EEPROM.read(address); address = address +1;
  task3HourE_Stored=EEPROM.read(address); address = address +1;
  task3MinE_Stored=EEPROM.read(address); address = address +1;
  task3SecE_Stored=EEPROM.read(address); address = address +1;
  
  
}


// Continuous function for converting bytes to decimals and vice versa
void loop() {
  readTime(); 
   
  if ((minute == task2MinS) & (hour == task2HourS)){
    digitalWrite(13, HIGH);   // set the LED on 
   }
   
   if ((minute == task2MinE) & (hour == task2HourE)){
    digitalWrite(13, LOW);   // set the LED on 
   }
   Serial.print("*********************************\n");
   Serial.print("Current time: ");
   printTime();
  Serial.println();
  Serial.print("************Schedules************\n");
  Serial.print("Task1:"); Serial.print("Starts at ");Serial.print(task1HourS_Stored);Serial.print("hours"); Serial.print(task1MinS_Stored);Serial.print("Minutes\t");
                          Serial.print("Stops at ");Serial.print(task1HourE_Stored);Serial.print("hours"); Serial.print(task1MinE_Stored);Serial.print("Minutes\n");
  Serial.print("Task2:"); Serial.print("Starts at ");Serial.print(task2HourS_Stored);Serial.print("hours"); Serial.print(task2MinS_Stored);Serial.print("Minutes\t");
                          Serial.print("Stops at ");Serial.print(task2HourE_Stored);Serial.print("hours"); Serial.print(task2MinE_Stored);Serial.print("Minutes\n");
  Serial.print("Task3:"); Serial.print("Starts at ");Serial.print(task3HourS_Stored);Serial.print("hours"); Serial.print(task3MinS_Stored);Serial.print("Minutes\t");
                          Serial.print("Stops at ");Serial.print(task3HourE_Stored);Serial.print("hours"); Serial.print(task3MinE_Stored);Serial.print("Minutes\n");
                   
  
     
          
  delay(1000);
  
}










byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}
byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}


// This set of codes is allows input of data
void setTime() {
  Serial.print("Please enter the current year, 00-99. - ");
  year = readByte();
  Serial.println(year);
  Serial.print("Please enter the current month, 1-12. - ");
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print("Please enter the current day of the month, 1-31. - ");
  monthday = readByte();
  Serial.println(monthday);
  Serial.println("Please enter the current day of the week, 1-7.");
  Serial.print("1 Sun | 2 Mon | 3 Tues | 4 Weds | 5 Thu | 6 Fri | 7 Sat - ");
  weekday = readByte();
  Serial.println(days[weekday-1]);
  Serial.print("Please enter the current hour in 24hr format, 0-23. - ");
  hour = readByte();
  Serial.println(hour);
  Serial.print("Please enter the current minute, 0-59. - ");
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println("The data has been entered.");
 
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}


byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9')
      reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}


void printTime() {
  char buffer[3];
  const char* AMPM = 0;
  readTime();
  Serial.print(days[weekday-1]);
  Serial.print(" ");
  Serial.print(months[month-1]);
  Serial.print(" ");
  Serial.print(monthday);
  Serial.print(", 20");
  Serial.print(year);
  Serial.print(" ");
  if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  }
  else AMPM = " AM";
  Serial.print(hour);
  Serial.print(":");
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  Serial.println(AMPM);
}


void readTime() {
  
  Wire.beginTransmission(DS1307);  
  Wire.write(byte(0));  
  Wire.endTransmission();  
  Wire.requestFrom(DS1307, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}

