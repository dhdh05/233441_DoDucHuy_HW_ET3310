#include <cstdio>
using namespace std;

//Bang
//Bang hoan vi IP
int IP[64]={
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

//IP-1
int IP1[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41,  9, 49, 17, 57, 25
};
//bang mo rong E: chuyen 32bit -> 48 bit
int E[48] = {
    32,  1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};
void hoanVi(int input[], int output[], int table[], int n){
    for (int i = 0; i < n; i++){
        //dau ra = vi tri dau vao tra trong bang 
        output[i] = input[table[i]-1]; 
    }
}

//PC func
int PC1[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};
int PC2[48] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

int P[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
};

int S[8][4][16] = {
    { {14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7},
      { 0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8},
      { 4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0},
      {15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13} },
    { {15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10},
      { 3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5},
      { 0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15},
      {13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9} },
    { {10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8},
      {13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1},
      {13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7},
      { 1,10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12} },
    { { 7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15},
      {13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9},
      {10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4},
      { 3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14} },
    { { 2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9},
      {14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6},
      { 4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14},
      {11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3} },
    { {12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11},
      {10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8},
      { 9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6},
      { 4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13} },
    { { 4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1},
      {13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6},
      { 1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2},
      { 6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3,12} },
    { {13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7},
      { 1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2},
      { 7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8},
      { 2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11} }
};

// o vi tri i+1 thi dich bao nhieu bit <trai>
int SHIFT[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int K[16][48];   // 16 khoa con, moi khoa 48 bit


//ham
//in bit ra hex
void inHex(int a[], int n){
    for (int i = 0; i < n; i= i + 4){
        printf("%x ", a[i]*8 + a[i+1] * 4 + a[i + 2 ] * 2 + a[i+3]);
    }
    printf("\n");
}

//dich loop sang trai
void dichTrai(int a[], int n, int s) {
    for (int count = 0; count < s; count++) {
        int tmp = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = tmp;
    }
}

//tao khoa
void taoKhoa(int key[]) {
    int cd[56], C[28], D[28], CD[56];
    hoanVi(key, cd, PC1, 56);

    //tach CD thanh C va D
    for (int i = 0; i < 28; i ++){
        C[i] = cd[i];
        D[i] = cd[i+28];
    }

    for (int i = 0; i < 16; i++) {
        dichTrai(C, 28, SHIFT[i]);
        dichTrai(D, 28, SHIFT[i]);

        //gop C va D thanh CD
        for (int i = 0; i < 28; i++){
            CD[i] = C[i];
            CD[i+28] = D[i];
        }

        hoanVi(CD, K[i], PC2, 48);
        printf("K%d = ", i + 1);
        inHex(K[i], 48);
    }
}


//in mang thanh ma tran
void inMatrix(int a[], int numCol, int n){
    for (int i = 0; i < n; i++){
        printf("b%d\t", a[i]);
        if (i % numCol == numCol -1) printf("\n");
    }
    printf("\n");
};

//F function

void F_function(int R[], int Ki[], int out[]) {
    int e[48], x[48], s32[32];

    hoanVi(R, e, E, 48);// mo rong E
    printf("    E(R)    = "); 
    inHex(e, 48);

    for (int i = 0; i < 48; i++){
        x[i] = e[i] ^ Ki[i];
    }
    
    printf("    E(R)^K  = "); inHex(x, 48);

    //chia thanh 8 Sbox
    for (int i = 0; i < 8; i++) {        
        int row = x[6*i] * 2 + x[6*i + 5];// bit dau + bit cuoi
        int col = x[6*i+1] * 8 + x[6*i+2] * 4 + x[6*i+3] * 2 + x[6*i+4];// 4 bit giua
        int v = S[i][row][col];
        s32[4*i]     = v / 8 % 2;
        s32[4*i + 1] = v / 4 % 2;
        s32[4*i + 2] = v / 2 % 2;
        s32[4*i + 3] = v % 2;
    }
    printf("  S-box    = "); inHex(s32, 32);

    // hoan vi P
    hoanVi(s32, out, P, 32);
    printf("    P   = "); inHex(out, 32);
}

int main(){

    printf("DES\n");
    //phan khai bao
    int plaintext[64];
    int ip_out[64]; //ket qua khi thuc hien IP
    int R0[32], L0[32];
    int e_out[48]; 
    int key[64] = {0};


    taoKhoa(key);

    // for (int i = 0; i < 64; i++){
    //     plaintext[i] = i;
    // }

    // //in ra plaintext
    // printf("Plaintext\n");
    // inMatrix(plaintext,8,64);

    // //in ra sau khi thuc hien IP
    // printf("Sau IP:\n");
    // hoanVi(plaintext, ip_out, IP, 64);
    // inMatrix(ip_out, 8, 64);

    // //quy uoc L0 la 32 phan tu dau, R0 la 32 phan tu sau
    // for (int i = 0; i< 32; i++){
    //     L0[i] = ip_out[i];
    //     R0[i] = ip_out[i+32];
    // }

    // //in L0 va R0
    // printf("L0:\n");
    // inMatrix(L0, 8, 32);
    // printf("R0:\n");
    // inMatrix(R0, 8, 32);

    // //mo rong E
    // hoanVi(R0, e_out, E, 48);
    // //in E
    // printf("E (R0)\n");
    // inMatrix(e_out, 6, 48);
    // int back[64];
    // hoanVi(ip_out, back, IP1, 64);
    // printf("IP^-1(IP(b)):\n"); inMatrix(back, 8, 64);

    //voi p = 0x000...1111
    int p[64] = {0};
    //0x1111 = 0001 0001 0001 0001
    p[51] = p[55] = p[59] = p[63] = 1;

    int x[64], L[32], R[32], f_out[32];
    hoanVi(p,x,IP,64);
    printf("IP_p: "); 
    inHex(x, 64);

    for (int i = 0; i< 32; i++){
        L[i] = x[i];
        R[i] = x[i+32];
    }

    // printf("Loop1:\n");
    // F_function(R, K[0], f_out);

    int newR[32];

    for (int round = 0; round < 16; round++) {
        printf("loop %d:\n", round + 1);
        F_function(R, K[round], f_out);

        for (int i = 0; i < 32; i++){
            newR[i] = L[i] ^ f_out[i];
        }
        for (int i = 0; i < 32; i++){
            L[i] = R[i];
            R[i] = newR[i];
        }


        printf("    L%d = ", round + 1); inHex(L, 32);
        printf("    R%d = ", round + 1); inHex(R, 32);
    }

    int RL[64], ciphertext[64];

    //ghep R, L
    for (int i = 0; i < 32; i++){
        RL[i] = R[i];
        RL[i+32] = L[i];
    }

    printf("R16L16 = "); inHex(RL, 64);

    hoanVi(RL, ciphertext, IP1, 64);
    printf("Ban ma C = "); inHex(ciphertext, 64);
    return 0;
}