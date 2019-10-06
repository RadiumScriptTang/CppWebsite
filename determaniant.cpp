#include <iostream>
#include <string>
#include <vector>
using namespace std;
double calculate_determainat(vector<vector<double>> A)
{
    // If the vector is null vector, return 0
    if(!A.size()) return 0;
    int n = A.size();
    int m = A[0].size();
    // If A is not a square matrix
    if( m != n ) return 0;
    // transfer the original determinant to a up-triangle matrix
    // so that the determinant can be calculated just by multiplying the elements on the main diagonal
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double k = -A[j][i] / A[i][i];
            for(int p = i; p < n; p++){
                A[j][p] += k * A[i][p];
            }
        }
    }
    // print the matrix in the screen
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    */
    double res = 1;
    for(int i = 0; i < n; i++){
        res *= A[i][i];
    }
    return res;
}
int main()
{
    cout << "Content-type:text/html\n\n";
    string line;
    cin >> line;
    int i = 0;
    string temp_string;
    int n = 0;
    int k = 0;
    vector<vector<double>> matrix;
    while(i < (int)line.size()){
        switch(line[i]){
            case 'n':
                i += 2;
                while(line[i] != '&'){
                    temp_string += line[i++];
                }
                n = atoi(temp_string.c_str());
                temp_string = "";
                matrix.resize(n,vector<double>(n));
                break;
            case 'x':
                i += 2;
                while(i < int(line.size())){
                    while(line[i] != '+'){
                        temp_string += line[i++];
                    }
                    matrix[k / n][k % n] = atof(temp_string.c_str());
                    temp_string = "";
                    k++;
                    i++;
                }
                break;
            default:
                i++;
                break;
        }
    }
    cout << calculate_determainat(matrix);
}
