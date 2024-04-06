/*!
@file       the name of source file is q.h
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   lab 8
@date       file created on 27/10/2023
@brief      provide a brief explanation about what this source file does:
            This file is contains 3 function declaraction be to called by 
            main in qdriver.
__________________________________________________________________________*/

#include <stdio.h> // for FILE*

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// initialize, wc, and print_freqs

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt);                         // takes in array (and size for size of array) and 2 pointer varriables and initilize them to zero
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt);                                // takes takes data from file and finds char type and adds them to the appropriate varraibles
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt);      // print the values sent to the function (size for array latin_frequency)
