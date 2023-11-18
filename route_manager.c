/** @file route_manager.c
 *  @brief A pipes & filters program that uses conditionals, loops, and string processing tools in C to process airline routes.
 *  @author Felipe R.
 *  @author Hausi M.
 *  @author Jose O.
 *  @author Saasha J.
 *  @author Victoria L.
 *  @author STUDENT_NAME
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The list of arguments passed to the program.
 * @return int 0: No errors; 1: Errors produced.
 *
 */


#define MAX_LENGTH 800
#define MAX_FLIGHTS 800

typedef struct {
    char airline_name[MAX_LENGTH];
    char airline_icao_unique_code[MAX_LENGTH];
    char airline_country[MAX_LENGTH];
    char from_airport_name[MAX_LENGTH];
    char from_airport_city[MAX_LENGTH];
    char from_airport_country[MAX_LENGTH];
    char from_airport_icao_unique_code[MAX_LENGTH];
    float from_airport_altitude;
    char to_airport_name[MAX_LENGTH];
    char to_airport_city[MAX_LENGTH];
    char to_airport_country[MAX_LENGTH];
    char to_airport_icao_unique_code[MAX_LENGTH];
    float to_airport_altitude;
    } Flight;



        void filter_for_4_arguments(int testing_for_empty_file, char *icao_code, char *destination_country, char *airline_name, char *airline_icao_unique_code, char *airline_country, char *from_airport_name, char *from_airport_city,  char *from_airport_country, char *from_airport_icao_unique_code, float from_airport_altitude, char *to_airport_name, char *to_airport_city, char *to_airport_country, char *to_airport_icao_unique_code, float to_airport_altitude){ 
            
            if (icao_code != NULL && destination_country != NULL && airline_icao_unique_code != NULL && to_airport_country != NULL){                                        
                    if ((strcmp(icao_code, airline_icao_unique_code) == 0) && strcmp(destination_country, to_airport_country) == 0){

                        FILE *fp1;
                    fp1 = fopen("output.txt", "a");
                    if(fp1 == NULL){
                        printf("can not open txt file");
                    }

                        fprintf(fp1, "FROM: %s, %s, %s TO: %s (%s), %s\n", from_airport_icao_unique_code, from_airport_city, from_airport_country, to_airport_name, to_airport_icao_unique_code, to_airport_city);
                        testing_for_empty_file++;
                        fclose(fp1);
                    } 
                                    
                    
                 
            }
           
        
        }

        void filter_for_5_arguments(int testing_for_empty_file, char *source_country, char *destination_city, char *destination_country, char *airline_name, char *airline_icao_unique_code, char *airline_country, char *from_airport_name, char *from_airport_city,  char *from_airport_country, char *from_airport_icao_unique_code, float from_airport_altitude, char *to_airport_name, char *to_airport_city, char *to_airport_country, char *to_airport_icao_unique_code, float to_airport_altitude){


            if (from_airport_country != NULL && to_airport_city != NULL && to_airport_country != NULL){
                    if ((strcmp(source_country, from_airport_country) == 0) && (strcmp(destination_city, to_airport_city) == 0) && (strcmp(destination_country, to_airport_country) == 0)){
                       
                        FILE *fp2;
                    fp2 = fopen("output.txt", "a");
                    if(!fp2){
                        printf("can not open txt file");
                    }

                        fprintf(fp2, "AIRLINE, %s, (%s), ORGIN, %s, %s, %s\n", airline_name, airline_icao_unique_code, from_airport_name, from_airport_icao_unique_code, from_airport_city);
                        testing_for_empty_file++;                      
                        fclose(fp2);
                    
                }
            
          }
    
        }

        void filter_for_6_arguments(int testing_for_empty_file, char *source_city, char *source_country, char *destination_city, char *destination_country, char *airline_name, char *airline_icao_unique_code, char *airline_country, char *from_airport_name, char *from_airport_city,  char *from_airport_country, char *from_airport_icao_unique_code, float from_airport_altitude, char *to_airport_name, char *to_airport_city, char *to_airport_country, char *to_airport_icao_unique_code, float to_airport_altitude){


            if (from_airport_city != NULL && from_airport_country != NULL && to_airport_city != NULL && to_airport_country != NULL){
                    if ((strcmp(source_city, from_airport_city) == 0) && (strcmp(source_country, from_airport_country) == 0) && (strcmp(destination_city, to_airport_city) == 0) && (strcmp(destination_country, to_airport_country) == 0)){
                    
                      FILE *fp3;
                    fp3 = fopen("output.txt", "a");
                    if(!fp3){
                        printf("can not open txt file");
                    }

                      
                        fprintf(fp3, "AIRLINE: %s, (%s) ROUTE: %s, %s\n", airline_name, airline_icao_unique_code, from_airport_icao_unique_code, to_airport_icao_unique_code);
                        testing_for_empty_file++;
                        fclose(fp3);
                   
                }
            }
        }

int main(int argc, char *argv[]){
    //creating tests to see if the file is empty
    int testing_for_empty_file = 0;

    //restarting the output.txt file
        FILE *fp9;
    fp9 = fopen("output.txt", "w");
    if(!fp9){
        printf("can not open txt file");
    }
    fclose(fp4);

//initializing the arguments
char icao_code[200] = "AAA";
char destination_country[200] = "AAA";
char source_country[200] = "AAA";
char destination_city[200] = "AAA";
char source_city[200] = "AAA";
char file_name[200] = "airline-routes-data.csv";

char *search_after;
 

int count = 0;

//argument processing
for (int i = 1; i < argc; i++){

    search_after = strchr(argv[i], '=');
    if (search_after == NULL){
        printf("Error: Invalid argument\n");
        return 1;

    }else if(strncmp(argv[i], "--DATA=", 7) == 0){
        strncpy(file_name, search_after + 1, 200);

    }else if (strncmp(argv[i], "--AIRLINE=", 10) == 0){
        strncpy(icao_code, search_after + 1, 200);

    }else if (strncmp(argv[i], "--DEST_COUNTRY=", 15) == 0){
        strncpy(destination_country, search_after + 1, 200);
    
    }else if (strncmp(argv[i], "--SRC_COUNTRY=", 14) == 0){
        strncpy(source_country, search_after + 1, 200);

    }else if (strncmp(argv[i], "--DEST_CITY=", 12) == 0){
        strncpy(destination_city, search_after + 1, 200);

    }else if (strncmp(argv[i], "--SRC_CITY=", 11) == 0){
        strncpy(source_city, search_after + 1, 200);
    
    }else{
        printf("Invalid argument");
        return 1;
    }

        count++;
}

//creating headers for the output.txt file
if (count == 3){

                 FILE *fp5;
                    fp5 = fopen("output.txt", "a");
                    if(fp5 == NULL){
                        printf("can not open txt file");
                    }
                fprintf(fp5, "FLIGHTS TO %s BY Air Canada (%s):\n", destination_country, icao_code);
                fclose(fp5);
}
if (count == 4){
    
                     FILE *fp6;
                        fp6 = fopen("output.txt", "a");
                        if(fp6 == NULL){
                            printf("can not open txt file");
                        }
                    fprintf(fp6, "FLIGHTS FROM %s TO %s, %s:\n", source_country, destination_city, destination_country);
                    fclose(fp6);
}
if (count == 5){
    
                     FILE *fp7;
                        fp7 = fopen("output.txt", "a");
                        if(fp7 == NULL){
                            printf("can not open txt file");
                        }
                    fprintf(fp7, "FLIGHTS FROM %s, %s TO %s, %s:\n", source_city, source_country, destination_city, destination_country);
                    fclose(fp7);
}
    

    //opening the file
    FILE *fp;
        fp = fopen("airline-routes-data.csv", "r");
        if ((ferror (fp))){
            printf("can not open file");
            return 1;
   	    }

    Flight Array[MAX_FLIGHTS];
    char line[MAX_LENGTH];
    int number_of_flights = 0;

        //skip first line
         fgets(line, sizeof(line), fp);
    
    while (fgets(line, sizeof(line), fp) != NULL) {

        //initializing the variables
        char airline_name[MAX_LENGTH];
        char airline_icao_unique_code[MAX_LENGTH];
        char airline_country[MAX_LENGTH];
        char from_airport_name[MAX_LENGTH];
        char from_airport_city[MAX_LENGTH];
        char from_airport_country[MAX_LENGTH];
        char from_airport_icao_unique_code[MAX_LENGTH];
        float from_airport_altitude;
        char to_airport_name[MAX_LENGTH];
        char to_airport_city[MAX_LENGTH];
        char to_airport_country[MAX_LENGTH];
        char to_airport_icao_unique_code[MAX_LENGTH];
        float to_airport_altitude;

            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^,],%[^,],%f",
            airline_name,
            airline_icao_unique_code,
            airline_country,
            from_airport_name,
            from_airport_city,
            from_airport_country,
            from_airport_icao_unique_code,
            &from_airport_altitude,
            to_airport_name,
            to_airport_city,
            to_airport_country,
            to_airport_icao_unique_code,
            &to_airport_altitude);

            number_of_flights++;
               
               //call the filters for the csv file
            if (count == 3){

        filter_for_4_arguments(testing_for_empty_file, icao_code, destination_country, airline_name, airline_icao_unique_code, airline_country, from_airport_name, from_airport_city, from_airport_country, from_airport_icao_unique_code, from_airport_altitude, to_airport_name, to_airport_city, to_airport_country, to_airport_icao_unique_code, to_airport_altitude);
        continue;

    }else if(count == 4){
        filter_for_5_arguments(testing_for_empty_file, source_city, destination_city, destination_country, airline_name, airline_icao_unique_code, airline_country, from_airport_name, from_airport_city, from_airport_country, from_airport_icao_unique_code, from_airport_altitude, to_airport_name, to_airport_city, to_airport_country, to_airport_icao_unique_code, to_airport_altitude);
        continue;

    }else if(count == 5){
        filter_for_6_arguments(testing_for_empty_file, source_city, source_country, destination_city, destination_country, airline_name, airline_icao_unique_code, airline_country, from_airport_name, from_airport_city, from_airport_country, from_airport_icao_unique_code, from_airport_altitude, to_airport_name, to_airport_city, to_airport_country, to_airport_icao_unique_code, to_airport_altitude);
        continue;

    }else{
        printf("Invalid number of arguments");
        return 1;
    }
    if (testing_for_empty_file == 0){
         FILE *fp10;
        fp4 = fopen("output.txt", "a");
            if (!fp10) {
        printf("can not open txt file");

        }fprintf(fp10, "NO RESULTS FOUND\n");
            fclose(fp10);
    }
    }
    
        
        

       //closing file
      fclose(fp);

    
    
     return 0;
 }


