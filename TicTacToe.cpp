#include<iostream>
using namespace std;
string n1 = "";
string n2 = "";
char arr[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row, column;
char token = 'x';
bool check = true; // assuming there is no space left
void fun1() {
    cout << "  " << arr[0][0] << " |  " << arr[0][1] << " | " << arr[0][2] << endl;
    cout << "____|____|_____" << endl;
    cout << "  " << arr[1][0] << " |  " << arr[1][1] << " | " << arr[1][2] << endl;
    cout << "____|____|_____" << endl;
    cout << "  " << arr[2][0] << " |  " << arr[2][1] << " | " << arr[2][2] << endl;
    cout << "    |    |     " << endl;
}

void fun2() { // choosing and filling
    char block;
    if (token == 'x') cout << n1 << " enter the block ";
    else cout << n2 << " enter the block ";
    cin >> block;
    if (block == '1') {
        row = 0;
        column = 0;
    }
    else if (block == '2') {
        row = 0;
        column = 1;
    }
    else if (block == '3') {
        row = 0;
        column = 2;
    }
    else if (block == '4') {
        row = 1;
        column = 0;
    }
    else if (block == '5') {
        row = 1;
        column = 1;
    }
    else if (block == '6') {
        row = 1;
        column = 2;
    }
    else if (block == '7') {
        row = 2;
        column = 0;
    }
    else if (block == '8') {
        row = 2;
        column = 1;
    }
    else if (block == '9') {
        row = 2;
        column = 2;
    }
    else {
        cout << "Invalid number chosen, choose from 1 to 9" << endl;
        return fun2();
    }

    if (token == 'x' and arr[row][column] != 'x' and arr[row][column] != 'o') {
        arr[row][column] = 'x';
        token = 'o';
    }
    else if (token == 'o' and arr[row][column] != 'x' and arr[row][column] != 'o') {
        arr[row][column] = 'o';
        token = 'x';
    }
    else {
        cout << "the compartment is already filled " << endl;
        fun2();
    }
}
bool fun3() {
    for (int i = 0; i < 3; i++) { // column 
        if (arr[0][i] == arr[1][i] and arr[1][i] == arr[2][i]) {
            if (arr[0][i] == 'x') {
                cout << n1 << " WINS!!!";
            }
            else {
                cout << n2 << " WINS!!!";
            }
            return false;
        }

    }
    for (int i = 0; i < 3; i++) { //rows
        if (arr[i][0] == arr[i][1] and arr[i][1] == arr[i][2]) {
            cout << ((arr[i][0] == 'x') ? n1 : n2) << " WINS!!!";
            return false;

        }
        //diagonal
        if (arr[0][0] == arr[1][1] and arr[1][1] == arr[2][2]) {
            cout << ((arr[0][0] == 'x') ? n1 : n2) << " WINS!!!";

            return false;
        }
        if (arr[0][2] == arr[1][1] and arr[1][1] == arr[2][0]) {
            cout << ((arr[0][2] == 'x') ? n1 : n2) << " WINS!!!";
            return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != 'x' and arr[i][j] != 'o') {
                    return true;
                }
            }
        }
        cout << "Its a DRAW!!";
        return false;
    }
}

int main() {
    cout << "       TIC TAC TOE            " << endl;
    cout << "enter the name of the players ";
    cin >> n1 >> n2;
    while (token != 'x' and token != 'o') {
        cout << "invalid token choosen, choose again from x or o ->";
        cin >> token;
    }

    while (fun3()) {
        cout << endl;
        fun1();
        cout << endl;
        fun2();
    }
    cout << endl;
    fun1();

}


