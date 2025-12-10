#include <iostream>

void print_array(int array[], int size){
    for (int i = 0; i < size; i++){
            std::cout << array[i] << '\n';
        }
    std::cout << "********************\n";
}

void input_scores(int array[], int size){
    int temp;

    for (int i = 0; i < size; i++){
        std::cout << "Enter score for round #" << i + 1 << ": ";
        std::cin >> temp;

        if((temp < 0)){
            break;
        }
        else{
            array[i] = temp;
        }
    }
}

void sort_scores(int array[], int size){
    int temp;

    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(array[j] < array[j+1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void search_score(int array[], int size, int target){
    for (int i = 0; i < size; i++){
        if(array[i] == target){
            std::cout << "Score found at rank " << i << '\n';
            return;
        }
        else{
            continue;
        }
    }
    std::cout << "Score not found. \n";
}

int main(){

    // --- Part 1 ---
    int scores[10];
    int size = sizeof(scores)/sizeof(scores[0]);
    std::fill(scores, scores + size, -1);
    
    print_array(scores, size);
    
    // --- Part 2 ---
    input_scores(scores, size);
    print_array(scores, size);
    
    // --- Part 3 ---
    sort_scores(scores, size);
    print_array(scores, size);
    
    // --- Part 4 ---
    search_score(scores, size, 550);
    
    // --- Final Part ---
    std::fill(scores, scores + size, 0);
    input_scores(scores, size);
    sort_scores(scores, size);

    for (int i = 0; (!(scores[i] == 0) && i < 3); i++){
        std::cout << scores[i] << '\n';
    }
    
    return 0;
}