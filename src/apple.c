#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
    //����n�@�Ɓ@�v�fk�@�̓���
    printf("input 'n' 'k':\n");
    scanf("%d%d", &n, &k);

    //k�̓��͐���
    int lb=-1, ub=1;
    int x=1;
  
    for(int i = 0; i < n; i++){
        printf("input number %d/%d :",i+1,n);
        scanf("%d", &A[i]);
        if (ub < A[i])ub = A[i];
    }
    x = ub;

    printf("input finished\n");

    int m = 0, sum = 0;

    while (ub - lb > 1) {

        //x��ݒ�
        x = (ub + lb) / 2;
        sum = 0;
        //x�̎��ɕK�v�Ȋ��̐�sum���v�Z
        for (int i = 0; i < n; i++) {
            sum += (A[i] + x - 1) / A[i];
        }
        //sum>=k�̎�ub�����炷�Asum<k�̎�lb�𑝂₷
        if (sum >= k) lb = x;
        else ub = x;

        //printf("x:%d,lb:%d,ub:%d,sum:%d\n", x, lb, ub, sum);

        m += 1;
        if (m > 100) break;
    }
    
    printf("Answer:%d\n", ub);
    return 0;
}