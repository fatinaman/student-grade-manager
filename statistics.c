#include "student.h"
#include "statistics.h"

float getHighest(Student *students, int count){
    if(count == 0){
        return -1.00;
    } else{
        float max = 0; // students can't score below 0
        for(int i = 0; i < count; i++){
            if (students[i].marks > max){
                max = students[i].marks;
            }
        }
        return max;
    }
}

float getAverage(Student *students, int count){
    if(count == 0){
        return -1.00;
    }else{
        float sum = 0.00;
        for(int i = 0; i < count; i++){
            sum += students[i].marks;
        }
        return sum / count;
    }
}