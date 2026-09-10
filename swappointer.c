    #include<stdio.h>
  2 void swap(int*a,int*b)
  3 {
  4     int temp;
  5     temp = *a;
  6     *a = *b;
  7     *b = temp;
  8 }
  9      int main()
 10 {
 11       int a,b;
 12       printf("Enter two integers :");
 13       scanf("%d %d",&a,&b);
 14       swap(&a,&b);
 15       printf("After swapping: a=%d ,b= %d ",a,b);
 16       return 0;
 17   }

