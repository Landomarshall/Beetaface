/*
 *
 * This file is part of the open-source SeetaFace engine, which includes three modules:
 * SeetaFace Detection, SeetaFace Alignment, and SeetaFace Identification.
 *
 * This file is an example of how to use SeetaFace engine for face detection, the
 * face detection method described in the following paper:
 *
 *
 *   Funnel-structured cascade for multi-view face detection with alignment awareness,
 *   Shuzhe Wu, Meina Kan, Zhenliang He, Shiguang Shan, Xilin Chen.
 *   In Neurocomputing (under review)
 *
 *
 * Copyright (C) 2016, Visual Information Processing and Learning (VIPL) group,
 * Institute of Computing Technology, Chinese Academy of Sciences, Beijing, China.
 *
 * The codes are mainly developed by Shuzhe Wu (a Ph.D supervised by Prof. Shiguang Shan)
 *
 * As an open-source face recognition engine: you can redistribute SeetaFace source codes
 * and/or modify it under the terms of the BSD 2-Clause License.
 *
 * You should have received a copy of the BSD 2-Clause License along with the software.
 * If not, see < https://opensource.org/licenses/BSD-2-Clause>.
 *
 * Contact Info: you can send an email to SeetaFace@vipl.ict.ac.cn for any problems.
 *
 * Note: the above information must be kept whenever or wherever the codes are used.
 *
 */

// #include <cstdint>

#include <iostream>
#include <fstream>
#include "string.h"
#include "stdlib.h"

// #include "opencv2/highgui/highgui.hpp"
// #include "opencv2/imgproc/imgproc.hpp"

// #include "face_detection.h"

using namespace std;

int filemode = 0;
char* filepath = NULL;

int shmmode = 0;
int shmid = 0;
int size = 0;

int jsonmode = 1;


void printUsage(){
    cout << "Usage:"<<endl;
    cout << " input parameters:" << endl;
    cout << " -n [name] specify input picture name" << endl;
    cout << " -shm [shid] specify share memory id" << endl;
    cout << " -size [size] specfy picture size" << endl;
    cout << " output parameters:" << endl;
    cout << " -encoding [encoding] specfy output encoding, `json` as default" << endl;
}

int processArgv(int argc, char** argv){
    for(int i = 1; i < argc; i++){
      if(argv[i][0] == '-'){
        if (strcmp(argv[i] + 1, "n") == 0){
          // specify name
          filemode = 1;
          if (i == argc -1){
            return 1;
          }
          filepath = argv[++i];      
        }else if (strcmp(argv[i] + 1, "shm") == 0){
          shmmode = 1;
        }else if (strcmp(argv[i] + 1, "size") == 0){
          if (i == argc - 1){
            return 1;
          }
          size = atoi(argv[++i]);
        }else if (strcmp(argv[i] + 1, "encoding") == 0){
          if (i == argc - 1){
            return 1;
          }
          if (strcmp(argv[++i], "json") == 0){
            jsonmode = 1;
          }else{
            return 1;
          }
        }else{
          return 1;
        }
      }else{
        return 1;
      }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2){
        printUsage();
        return 1;
    }
    int err = processArgv(argc, argv);
    if (err) {
      printUsage();
      return 1;
    }
    
    // file input mode 
    if (filemode){

    }else if (shmmode){

    }

    // info output mode
    if (jsonmode){

    }
    return 0;
}
