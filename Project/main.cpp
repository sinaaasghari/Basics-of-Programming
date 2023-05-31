#include<iostream>
#include<math.h>
using namespace std;
float a[10][10];
float b[10][10];
float c[10][10];
float inverse[10][10];
float t;
float row_a, col_a;
float row_b, col_b;
float detr_a , detr_b;
void inverse_ro_briz_to_b(){
    for(int i= 0; i < row_b; i++){
        for(int j = 0; j < col_b; j++){
            b[i][j] = inverse[i][j];
        }
    }
    return;
}
void c_ro_briz_to_a(){
    col_a = col_b;
    for(int i= 0; i < row_a; i++){
        for(int j = 0; j < col_b; j++){
            a[i][j] = c[i][j];
        }
    }
    return;
}
void a_ro_begir() {
    cout << "andazeye matrix_A ra dar do adad vared konid :\n";
    cin >> row_a >> col_a;
    if(row_a > 10 || col_a > 10){
        cout << "andaze ha dorost nist!\n ";
        return;  
    }
    else{
    for (int i = 0; i < row_a; i++){
        for(int j = 0; j < col_a; j++){
            //cout << "a[" << i<<"]" << "[" << j << "]= ";//
            cin >> a[i][j];
        }
    }
}
    return;
}
void b_ro_begir(){
    cout << "andazeye matrix_B ra dar do adad vared konid :\n";
    cin >> row_b >> col_b;
    if(row_b > 10 || col_b > 10){
        cout << "andaze ha dorost nist!\n ";  
    }
    else{
    for (int i = 0; i < row_b; i++){
        for(int j = 0; j < col_b; j++){
            //cout << "b[" << i<<"]" << "[" << j << "]= ";//
            cin >> b[i][j];
        }
    }
}
    return;

}
void a_ro_briz_to_b(){
    row_b = row_a;
    col_b = col_a;
    for(int i= 0; i < row_a; i++){
        for(int j = 0; j < col_a; j++){
            b[i][j] = a[i][j];
        }
    }
    return;
}
void b_ro_briz_to_a(){
    row_a = row_b;
    col_a = col_b;
    for(int i= 0; i < row_b; i++){
        for(int j = 0; j < col_b; j++){
            a[i][j] = b[i][j];
        }
    }
    return;
}
void a_dar_b_zarb(){
    if(col_a != row_b){
        cout << "zarb emkan pazir nist!";
        return;
    }
    else{
        for(int i= 0; i < row_a; i++){
            for(int j = 0; j < col_b; j++){
                c[i][j] = 0;
                for(int t = 0; t < col_a; t++){
                    c[i][j] += a[i][t] * b[t][j];
                }
            }
        }
    }
    c_ro_briz_to_a();
    return;

}
void a_ba_b_gam(){
    
    if( row_a != row_b || col_a != col_b){
    cout << "emkan gam vojod nadarad!";
        return;
    }
    else{
        for(int i= 0; i < row_a; i++){
            for(int j = 0; j < col_a; j++){
            a[i][j] += b[i][j];
        }
    }
    }
    return;
}
void a_mnhaye_b(){
    if( row_a != row_b || col_a != col_b){
        cout << "emkan tafrigh vojod nadarad!" << endl;
        return;
    }
    else{
        for(int i= 0; i < row_a; i++){
        for(int j = 0; j < col_a; j++){
            a[i][j] -= b[i][j];
        }
    }
    }
    return;
}
void adad_dar_matrix_a(float zarib = 0){
    cout << " adadi k dar matrix_A mikhahid zard konid ra vared konid:\n";
    cin >> zarib;
    for(int i= 0; i < row_a; i++){
        for(int j = 0; j < col_a; j++){
            a[i][j] *= zarib;
        }
    }
    return;
}
void bast_dadan(float b[10][10], float temp[10][10], float p, float q, float n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = b[row][col];
 
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return;
}
float det_b(float b[10][10], float row_b)
{
	float D = 0; 

	if (row_b == 1)
		return b[0][0];

	float temp[10][10];

	float sign = 1; 

	for (int f = 0; f <  row_b; f++)
	{
		bast_dadan(b, temp, 0, f,  row_b);
		D += sign * b[0][f] * det_b(temp,  row_b - 1);

		sign = -sign;
	}

	return D;
}
void adjoint(float b[10][10],float adj[10][10])
{
    if (row_b == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    float sign = 1, temp[10][10];
 
    for (int i = 0; i < row_b; i++)
    {
        for (int j = 0; j < row_b; j++)
        {   
           bast_dadan(b, temp, i, j, row_b);
 
            sign = ((i+j)%2==0)? 1: -1;
 
            adj[j][i] = (sign) * det_b(temp, row_b - 1);
        }
    }
}
bool varoon(float b[10][10],float inverse[10][10])
{
    float det = det_b(b, row_b);
    if (det == 0)
    {
        cout << "Matrix B makoos nadarad!" << endl;
        return false;
    }
    float adj[10][10];
    adjoint(b, adj);
 
    for (int i = 0; i < row_b; i++){
        for (int j = 0; j < col_b; j++){
            inverse[i][j] = adj[i][j]/float(det);
        }
    }
    return true;
}
void taghsim_a_bar_b(){
    varoon(b, inverse);
    inverse_ro_briz_to_b();
    a_dar_b_zarb();
}
void chap_a(){
    cout << "Matrix_A =\n";
    for(int i= 0; i < row_a; i++){
        cout << "|";
        for(int j = 0; j < col_a; j++){
            cout << a[i][j] <<" ";
        }
        cout <<"\b";
        cout << "|" << "\n";
    }
    return;

}
void chap_b(){
    cout << "Matrix_B =\n";
    for(int i= 0; i < row_b; i++){
        cout << "|";
        for(int j = 0; j < col_b; j++){
            cout << b[i][j] <<" ";
        }
        cout <<"\b";
        cout << "|" << "\n";   
    }
    return;
}
int main(){
    cout << "-----------------------------------" << endl;
    cout << "1- daryaft matrix A\n2- daryaft matrix A\n3- enteghal A be B\n4- enteghal B be A\n5- A= A*B\n6- A = A+B\n7- A = A/B\n8- A = A - B\n9- A = a*A\n10-det A\n11-det B \n12-chap A\n13-chap B\n";
    cout << "-----------------------------------" << endl;
    int dastoor;
    cout << "dastoor ra vared konid: ";
    cin >> dastoor;
    while (true) {
        switch (dastoor)
        {
        case 1 :
            a_ro_begir();
            break;
        case 2 :
            b_ro_begir();
            break;
        case 3 :
            a_ro_briz_to_b();
            break;
        case 4 :
            b_ro_briz_to_a();
             break;     
        case 5 :
           a_dar_b_zarb();
            break;
        case 6 :
            a_ba_b_gam();
             break;
        case 7 :
            varoon(b, inverse);
            inverse_ro_briz_to_b();
            a_dar_b_zarb();
            break;
        case 8 :
            a_mnhaye_b();
             break; 
        case 9 :
            adad_dar_matrix_a();
            break;
        case 10 :
            if(row_a == col_a){
            cout<<"Determinan matrix_A: "<< det_b(a, row_a) << endl;
            break;
            }
            else{
                cout << "matrix moarabayr nist\n";
                break;
            } 
        case 11 :
            if(row_b == col_b){
            cout<<"Determinan matrix_B: "<< det_b(b, row_b) << endl;
            break;
            }
            else{
                cout << "matrix moarabayr nist\n";
                break;
            }
        case 12 :
             chap_a();
             break; 
        case 13 :
             chap_b();
            break;
        default:
            cout << "dastoor ghalat ast!\n";
            break;
        }
    cout << "dastoor ra vared konid: ";
    cin >> dastoor;
    }
    
}