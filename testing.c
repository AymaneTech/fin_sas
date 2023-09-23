 #include <stdio.h>
 #include <time.h>
 int main (){
 time_t current_time;
    struct tm *local_time_info;

    time(&current_time);
    local_time_info = localtime(&current_time);

    printf("Current local time and date: %s", asctime(local_time_info));
 }