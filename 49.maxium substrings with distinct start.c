#include <stdio.h>
#include <string.h>

int maxDistinct(char* s){
    int used[26] = {0};
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++){
        int c = s[i] - 'a';
        if(!used[c]){
            used[c] = 1;
            count++;
        }
    }
    return count;
}

int main(){
    char s[100005];
    printf("Enter string: ");
    scanf("%s", s);

    int ans = maxDistinct(s);
    printf("Answer: %d\n", ans);

    return 0;
}
