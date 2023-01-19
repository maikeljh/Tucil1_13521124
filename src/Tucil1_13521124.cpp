#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

int converterInput(string x){
    if(x == "A"){
        return 1;
    } else if(x.length() == 1 && x[0] - '0' > 0 && x[0] - '0' < 11){
        return stoi(x);
    } else if(x == "10"){
        return 10;
    } else if(x == "J"){
        return 11;
    } else if(x == "Q"){
        return 12;
    } else if(x == "K"){
        return 13;
    } else {
        return -1;
    }
}

double calTwoNumber(double a, double b, char x) {
    if(x == '+'){
        return a + b;
    } else if (x == '-'){
        return a - b;
    } else if (x == '*'){
        return a * b;
    } else if (x == '/'){
        double aTemp = a;
        double bTemp = b;
        return aTemp / bTemp;
    }
}

bool validCalculation(double a, double b, char x){
    if(x == '/'){
        if(b == 0){
            return false;
        }
    }

    return true;
}

int main(){
    // DECLARATION
    string action;
    string a, b, c, d;
    int firstNumber, secondNumber, thirdNumber, fourthNumber;
    time_t start, ending;
    bool done = false;
    ifstream file;
    ofstream outdata;
    srand(time(0));

    while(!done){
        bool valid = false;

        // WELCOME
        printf("\n@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@\n");
        printf("@@#7^::::::::::::::::::::::::::::::::::::::::^7#@@\n");
        printf("@@!                                            !@@\n");
        printf("@@~                                            ~@@\n");
        printf("@@~            .:::.       ....    ....        ~@@\n");
        printf("@@~         .!J5PPPPY!    !555P?  ?555PJ       ~@@\n");
        printf("@@~        75PP55555PBY   YP55PY  YP55PP       ~@@\n");
        printf("@@~       ?P555PP55555B! .Y555PJ  JP55PP       ~@@\n");
        printf("@@~       75PP5!^Y5555B7 .Y555GJ  ?P55PP.      ~@@\n");
        printf("@@~        .~~. .Y555PG: .Y555PP??Y555PP.      ~@@\n");
        printf("@@~             ?P555G!   JP5555PP5555PP.      ~@@\n");
        printf("@@~            7P555G?    ?PPPPPPP5555PP.      ~@@\n");
        printf("@@~           ?P555P?     :7??????5555PP.      ~@@\n");
        printf("@@~         .JP555P?              ?P55PP.      ~@@\n");
        printf("@@~        .JP555P7               JP55PP       ~@@\n");
        printf("@@~       .JP555G7 .....          JP55PP       ~@@\n");
        printf("@@~       7P5555P555555G~         Y555P5       ~@@\n");
        printf("@@~       JP555555PP555BJ        .5P55G5       ~@@\n");
        printf("@@~       ?55555555555Y5~         JY5YY!       ~@@\n");
        printf("@@~        ............            ...         ~@@\n");
        printf("@@~                                            ~@@\n");
        printf("@@!                                            !@@\n");
        printf("@@#7^::::::::::::::::::::::::::::::::::::::::^7#@@\n");
        printf("@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@\n");
        printf("\nWelcome to the 24 Game!\n");

        // SELECTION TYPE OF INPUT
        while(!valid){
            printf("Please choose which type of input do you want:\n");
            printf("1. Input from user\n");
            printf("2. Generate input\n");
            printf("Choose (1 or 2) : ");
            cin >> action;

            if(action == "1"){
                // INSTRUCTION
                printf("\nYour cards (ex: A 10 Q J): ");

                // INPUT
                cin >> a >> b >> c >> d;

                // CONVERT INPUT TO INTEGER
                firstNumber = converterInput(a);
                secondNumber = converterInput(b);
                thirdNumber = converterInput(c);
                fourthNumber = converterInput(d);

                // VALIDATION
                while(firstNumber == -1 || secondNumber == -1 || thirdNumber == -1 || fourthNumber == -1){
                    cout << "ERROR! Please input the right form!" << endl;
                    printf("\nYour cards (ex = A 10 Q J): ");
                    cin >> a >> b >> c >> d;
                    firstNumber = converterInput(a);
                    secondNumber = converterInput(b);
                    thirdNumber = converterInput(c);
                    fourthNumber = converterInput(d);
                }

                valid = true;
            } else if (action == "2") {
                string cards[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

                int index1 = rand() % 13;
                int index2 = rand() % 13;
                int index3 = rand() % 13;
                int index4 = rand() % 13;

                firstNumber = converterInput(cards[index1]);
                secondNumber = converterInput(cards[index2]);
                thirdNumber = converterInput(cards[index3]);
                fourthNumber = converterInput(cards[index4]);

                cout << "\nYour cards : " << cards[index1] << " " << cards[index2] << " " << cards[index3] << " " << cards[index4] << endl;
                valid = true;
            } else {
                cout << "\nWRONG INPUT! Please input correctly!\n" << endl;
            }
        }

        // MAIN GAME
        int num[4] = {firstNumber, secondNumber, thirdNumber, fourthNumber};
        char operators[4] = {'+', '-', '*', '/'};
        vector<string> ans;
        int count = 0;
        double timeConsumed = clock();

        for(int firstIdx = 0; firstIdx < 4; firstIdx++){
            for(int secondIdx = 0; secondIdx < 4; secondIdx++){
                for(int thirdIdx = 0; thirdIdx < 4; thirdIdx++){
                    for(int i = 0 ; i < 4; i++){
                        for(int j = 0; j < 4; j++){
                            for(int k = 0; k < 4; k++){
                                for(int l = 0; l < 4; l++){
                                    if(i != j && i != k && i != l && j != k && j != l && k != l){
                                        string answer;
                                        // FIRST COMBINATION
                                        if(validCalculation(num[i], num[j], operators[firstIdx]) && 
                                            validCalculation(calTwoNumber(num[i], num[j], operators[firstIdx]), num[k], operators[secondIdx]) &&
                                            validCalculation(calTwoNumber(calTwoNumber(num[i], num[j], operators[firstIdx]), num[k], operators[secondIdx]), num[l], operators[thirdIdx])){
                                                double cal = calTwoNumber(
                                                    calTwoNumber(
                                                        calTwoNumber(num[i], num[j], operators[firstIdx]), num[k], operators[secondIdx]
                                                    ), 
                                                    num[l], operators[thirdIdx]
                                                );
                                                if(cal == 24){
                                                    answer = "((" + to_string(num[i]) + " " +
                                                                        operators[firstIdx] + " " + to_string(num[j]) + ") " +
                                                                        operators[secondIdx] + " " + to_string(num[k]) + ") " +
                                                                        operators[thirdIdx] + " " + to_string(num[l]);
                                                    if(find(ans.begin(), ans.end(), answer) == ans.end()){
                                                        count++;
                                                        ans.push_back(answer);
                                                    }
                                                }
                                        }

                                        // SECOND COMBINATION
                                        if(validCalculation(num[i], num[j], operators[firstIdx]) &&
                                            validCalculation(num[k], num[l], operators[thirdIdx]) &&
                                            validCalculation(calTwoNumber(num[i], num[j], operators[firstIdx]), calTwoNumber(num[k], num[l], operators[thirdIdx]), operators[secondIdx])) {
                                                double hasil1 = calTwoNumber(num[i], num[j], operators[firstIdx]);
                                                double hasil2 = calTwoNumber(num[k], num[l], operators[thirdIdx]);
                                                double cal = calTwoNumber(
                                                            hasil1, 
                                                            hasil2, 
                                                            operators[secondIdx]
                                                        );
                                                if(cal == 24){
                                                    answer = "(" + to_string(num[i]) + " " +
                                                                        operators[firstIdx] + " " + to_string(num[j]) + ") " +
                                                                        operators[secondIdx] + " (" + to_string(num[k]) + " " +
                                                                        operators[thirdIdx] + " " + to_string(num[l]) + ")";
                                                    if(find(ans.begin(), ans.end(), answer) == ans.end()){
                                                        count++;
                                                        ans.push_back(answer);
                                                    }
                                                }
                                        }

                                        // THIRD COMBINATION
                                        if(validCalculation(num[j], num[k], operators[secondIdx]) && 
                                            validCalculation(num[i], calTwoNumber(num[j], num[k], operators[secondIdx]), operators[firstIdx]) && 
                                            validCalculation(calTwoNumber(num[i], calTwoNumber(num[j], num[k], operators[secondIdx]), operators[firstIdx]),num[l], operators[thirdIdx])) {
                                                double cal = calTwoNumber(
                                                    calTwoNumber(num[i], 
                                                                calTwoNumber(num[j], num[k], operators[secondIdx]), 
                                                                operators[firstIdx]),
                                                    num[l], 
                                                    operators[thirdIdx]
                                                );
                                                if(cal == 24){
                                                    answer = "(" + to_string(num[i]) + " " +
                                                                        operators[firstIdx] + " (" + to_string(num[j]) + " " +
                                                                        operators[secondIdx] + " " + to_string(num[k]) + ")) " +
                                                                        operators[thirdIdx] + " " + to_string(num[l]);
                                                    if(find(ans.begin(), ans.end(), answer) == ans.end()){
                                                        count++;
                                                        ans.push_back(answer);
                                                    }
                                                }
                                        }

                                        // FOURTH COMBINATION
                                        if(validCalculation(num[j], num[k], operators[secondIdx]) &&
                                            validCalculation(calTwoNumber(num[j], num[k], operators[secondIdx]), num[l], operators[thirdIdx]) &&
                                            validCalculation(num[i], calTwoNumber(calTwoNumber(num[j], num[k], operators[secondIdx]), num[l], operators[thirdIdx]), operators[firstIdx])) {
                                                double cal = calTwoNumber( num[i], 
                                                            calTwoNumber(
                                                                calTwoNumber(num[j], num[k], operators[secondIdx]), 
                                                                num[l], 
                                                                operators[thirdIdx]
                                                            ), 
                                                            operators[firstIdx]
                                                        );
                                                if(cal == 24){
                                                    answer = to_string(num[i]) + " " +
                                                                        operators[firstIdx] + " ((" + to_string(num[j]) + " " +
                                                                        operators[secondIdx] + " " + to_string(num[k]) + ") " +
                                                                        operators[thirdIdx] + " " + to_string(num[l]) + ")";
                                                    if(find(ans.begin(), ans.end(), answer) == ans.end()){
                                                        count++;
                                                        ans.push_back(answer);
                                                    }
                                                }
                                        }
                                    } else {
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        timeConsumed = clock() - timeConsumed;

        // OUTPUT
        if(count == 0){
            printf("\nTidak ada solusi\n");
        } else {
            printf("\n%d solutions found\n", count);
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << endl;
            }              
        }

        // TIME EXECUTION
        cout << "Total time required = " << (double)timeConsumed/CLOCKS_PER_SEC << " seconds" << endl;

        // OPTION TO SAVE FILE
        while(true){
            printf("\nDo you want to save the answer? (y/n) : ");
            cin >> action;
            if(action == "y"){
                string nameFile;
                while(true){
                    printf("\nPlease input new name file : ");
                    cin >> nameFile;
                    nameFile += ".txt";
                    file.open(nameFile);
                    if(file){
                        printf("\nFile already exist! Please input a new name file!\n");
                    } else {
                        outdata.open("../output/" + nameFile);
                        if(count != 0){
                            outdata << count << " solutions found" << endl;
                            for(int i = 0; i < ans.size(); i++){
                                outdata << ans[i] << endl;
                            }
                        } else {
                            outdata << "Tidak ada solusi" << endl;
                        }
                        outdata << "Total time required = " << (double)timeConsumed/CLOCKS_PER_SEC << " seconds" << endl;
                        outdata.close();
                        cout << "\nFile " << nameFile << " has been created" << endl;
                        break;
                    }
                }
                break;
            } else if(action == "n"){
                break;
            } else {
                printf("\nWRONG INPUT! Please input correctly!\n");
            }
        }

        while(true){
            printf("\nDo you want to play again? (y/n) : ");
            cin >> action;
            if(action == "y"){
                break;
            } else if (action == "n"){
                printf("\nThank you for playing!\n");
                done = true;
                break;
            } else {
                printf("\nWRONG INPUT! Please input correctly!\n");
            }
        }
    }
}