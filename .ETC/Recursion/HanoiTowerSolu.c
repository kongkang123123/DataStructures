// 열혈 자료구조 p.71
#include <stdio.h>

// from에 꽂혀있는 num개의 원반은 by로 거쳐서 to로 이동
void HanoiTowerMove(int num, char from, char by, char to) {

    if(num == 1) {      // 이동할 원반의 수가 1개. 재귀의 탈출 조건
        printf("Move Disk #1 from %c to %c\n", from, to);
        return ;
    }

    HanoiTowerMove(num-1, from, to ,by);                    // 가장 밑 원반 제외한 n-1개를 A에서 B로 이동
    printf("Move Disk #%d from %c to %c\n", num, from, to); // 가장 밑 원반 1개를 A에서 C로 이동
    HanoiTowerMove(num-1, by, from, to);                    // n-1개 원반들을 B에서 C로 이동
}

int main(void) {

    // 막대 A의 원반 7개를 막대B를 경유하여 막대C로 옮기기
    HanoiTowerMove(7, 'A', 'B', 'C');
    return 0;
}