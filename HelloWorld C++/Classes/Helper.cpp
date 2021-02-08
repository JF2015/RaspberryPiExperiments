#include "Helper.h"
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <cstring>


double Helper::get_temp()
{
  const int BUFFER_SIZE = 100;
  char data[BUFFER_SIZE];
  FILE *finput;
  size_t bytes_read;
  double temp = -1000;
  finput = fopen("/sys/class/thermal/thermal_zone0/temp","r");
  if (finput != NULL) 
  {
    memset(data,0,BUFFER_SIZE);
    fread(data,BUFFER_SIZE,1,finput);
    temp = atoi(data);
    temp /= 1000;
    fclose(finput);
  }
  return temp;
}