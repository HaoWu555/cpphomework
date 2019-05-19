#include <stdio.h>

int puzzle[6][8], press[6][8];
/*
推测验证过程：
根据第一行猜测
*/
bool guess() {
    int c, r;
    //根据press第1行和puzzle数组，计算press其他行的值
    for(r=1; r<5; r++) {
        for(c=1; c<7; c++) {
            press[r+1][c]=(puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1])%2;
        }
    }
    //判断所计算的press数组能否熄灭第5行的所有灯
    for(c=1; c<7; c++) {
        if ((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2 != puzzle[5][c]) {
            return false;
        }
    }
    return true;
}

/*
枚举过程：
对press第1行的元素press[1][1]~press[1][6]的各种取值进行枚举
*/
void enumerate() {
    int c;
    bool success; //这个变量时当时定义了没排上用场吧，NodYoung注
    for(c=1; c<7; c++) {
        press[1][c]=0;
    }
    while(guess()==false) {
        press[1][1]++;
        c=1;
        while(press[1][c]>1) {  //累加进位
            press[1][c]=0;
            c++;
            press[1][c]++;
        }
    }
    return ;
}

int main() {
    int cases, i, r, c;
    scanf("%d", &cases);
    for(r=0; r<6; r++) {
        press[r][0]=press[r][7]=0;
    }
    for(c=0; c<7; c++) {
        press[0][c]=0;
    }
    for(i=0; i<cases; i++) {
        for(r=1; r<6; r++) {
            for(c=1; c<7; c++) {
                scanf("%d", &puzzle[r][c]); //读入输入数据
            }
        }
        enumerate();
        printf("PUZZLE#%d\n", i+1);
        for (r=1; r<6; r++) {
            for (c=1; c<7; c++) {
                printf("%d ", press[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}
