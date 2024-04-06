/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   lab 8
@date       file created on 27/10/2023
@brief      provide a brief explanation about what this source file does:
            This file is contains 3 function definitions be to called by 
            main in qdriver the 6 functions are 
            - void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt)                        // takes in array (and size for size of array) and 2 pointer varriables and initilize them to zero
            - void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt)                               // takes takes data from file and finds char type and adds them to the appropriate varraibles
            - void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt)     // print the values sent to the function
________________________________________________________________________________________________________ ______*/

#include <stdio.h>   // do not remove

// IMPORTANT NOTE: Other than functions fgetc, printf, or fprintf [which are declared in <stdio.h>],
// you must not use any other C standard library function in your submission.

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...
// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...
// For each function -
// Add documentation [for yourself and not for grading] for the function ...
void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt){
    for(int i = 0; i != size; i++){latin_freq[i] = 0;}                                  //initilizing all values in array to zero 
    *ctrl_cnt = 0;                                                                      //initilizing pointer varriable to zero
    *non_latin_cnt = 0;                                                                 //initilizing pointer varriable to zero
}
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
    /*
        int BASE_LETTER_ASCII = 65, LETTER-SHIFT = 32, i=0, ch = 0;
        while( (ch = fgetc(ifs)) != EOF){ for(int i = 0; i != size; i++){
            if(ch == (BASE_LETTER_ASCII + i) || ch == (BASE_LETTER_ASCII + LETTER-SHIFT + i)){ latin_freq[i] +=1; } }
            else if( (ch >= 7 && ch <= 13) ){ *ctrl_cnt +=1; }
            else{ non_latin_cnt +=1; }
    */
    int ch, position = 0;
    while( (ch = fgetc(ifs)) != EOF){
        if((ch >= 'A' && ch <= 'Z' )||(ch >= 'a' && ch <= 'z')){ 
            
            if(ch >= 'a' && ch <= 'z'){ ch -= 32;}                                                 // converting lowercase to uppercase
            position = ch - 'A';

            latin_freq[position]++; 
        }
        else if( (ch >= 0 && ch <= 31) || ch == 127 ){ *ctrl_cnt +=1; }
        else{ *non_latin_cnt +=1; }
    }
}
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt){
    char letter = 'a';
    int total_latin_letters = 0;
    FILE *out = stdout;                                                                             // setting FILE pointer to out to output string into file

    for(int i = 0; i != size; i++){                                                                 // printing all the alphabets
        fprintf(out,"%-10c", letter++); 
    }fprintf(out,"\n");

    for(int i = 0; i != size; i++){                                                                 // printing the number of each alphabets found in the file
        fprintf(out,"%-10d", latin_freq[i]);
        total_latin_letters += latin_freq[i];                                                       // summing total number of alphabets in the file
    }fprintf(out,"\n\n");

    //printing all out to the file
    fprintf(out,"Latin Letters     :%8d\n", total_latin_letters);
    fprintf(out,"Non-Latin Letters :%8d\n", *non_latin_cnt);
    fprintf(out,"Control Letters   :%8d\n", *ctrl_cnt);
}
