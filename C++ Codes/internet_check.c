#include<stdio.h>
#include<stdint.h>
uint16_t internet_checksum(uint16_t data[],int l){
    uint16_t sum=0;
    for(int i=0;i<l;i++){
        sum+=data[i];
    
     if (sum > 0xFFFF) {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }
    }
    return ~sum;
}
int main(){
    uint16_t data[1]={0xFFFFF};
    uint16_t c = internet_checksum(data,1);
    printf("0x%04X",c);
}