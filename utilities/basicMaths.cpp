#include "../header_files/utilities.h"

int getMid(int a, int b){
    return a + ( b - a ) / 2;
}

int getNoOfDigits(int a){
    if (!a) return 1;
    int c = 0;
    while(a != 0){
        a = a / 10;
        c++;
    }
    return c;
}

int power(int a, int b){
    int ans = 1;
    while(b--){
        ans = ans * a;
    }
    return ans;
}


void printLevel(int* temp, int height, int level, int special){
    int constantSpace = 4;
    int n = level;
    int midSpace = 3;
    while(n--)
        midSpace = 2 * midSpace + 1;
    n = level;
    int addValue = 0;
    int addingValue = midSpace / 4;
    while(n--){
        addValue += addingValue + 1; 
        addingValue /= 2;
    }
    int initialSpace = constantSpace + addValue; 

    for(int i = 0 ;i < initialSpace ; i++) cout << " ";
    int j = 0;

    for(int i = power(2, height - level) - 1 ; i >= 0 ; i--){
        if(special & power(2, i)) cout <<temp[j++];
        else cout << " ";
        for(int i = 0 ; i < midSpace ; i++) cout << " ";
    }
}

void printLevelWithBlock(int* temp, int height, int level, int special){
    int constantSpace = 4;
    int initialSpace = constantSpace + power(2, level + 2) - 4;
    int n = level;
    int midSpace = 3;
    while(n--)
        midSpace = 2 * midSpace + 5;
    for(int i = 0 ;i < initialSpace ; i++) cout << " ";

    int j = 0;
    
    for(int i = power(2, height - level) - 1 ; i >= 0 ; i--){
        
        for(int i = 0; i< 5 ; i++) cout << "-";
        for(int i = 0 ; i < midSpace ; i++) cout << " ";
    }
    cout << endl;
    for(int i = 0 ;i < initialSpace ; i++) cout << " ";
    for(int i = power(2, height - level) - 1 ; i >= 0 ; i--){
        
        if(special & power(2, i)) cout <<"| " <<temp[j++] << " |";
        else cout << "|   |";
        for(int i = 0 ; i < midSpace ; i++) cout << " ";
    }
    cout << endl;
    for(int i = 0 ;i < initialSpace ; i++) cout << " ";
    for(int i = power(2, height - level) - 1 ; i >= 0 ; i--){
        
        for(int i = 0; i< 5 ; i++) cout << "-";
        for(int i = 0 ; i < midSpace ; i++) cout << " ";
    }
    if(level){
        cout << endl;
        if(level >= 3){
            for(int i = 0 ; i < initialSpace - 2 * level; i++) cout << " ";
            for(int i = 0 ; i < level ; i++) cout << "_";
            for(int j = 0 ; j < power(2, height - level) ; j++){
                cout << "/";
                for(int i = 0; i < 5 + 2 * (level - 1) ; i++) cout << " ";
                cout << "\\";
                for(int i = 0 ; i < level ; i++) cout << "_";
                for(int i = 0; i < midSpace - 4*(level) ; i++) cout << " ";
                if (j < power(2, height - level) - 1)
                    for(int i = 0 ; i < level ; i++) cout << "_";
            }

        }
        else{
            for(int i = 0 ; i < initialSpace - level; i++) cout << " ";
            for(int j = 0 ; j < power(2, height - level) ; j++){
                cout << "/";
                for(int i = 0; i < 5 + 2 * (level - 1) ; i++) cout << " ";
                cout << "\\";
                for(int i = 0; i < midSpace - 2*(level) ; i++) cout << " ";
            }
        }
            
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}


