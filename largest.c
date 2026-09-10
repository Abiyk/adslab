 #include<stdio.h>
  2 int largest(int a[],int n)
  3 {
  4     int i,max =a[0];
  5     for(i=1;i<n;i++)
  6 {
  7     if(a[i]>max)
  8     {
  9         max = a[i];
 10 }
 11 }
 12 return max;
 13 }
 14 int main()
 15         {
 16         int a[5]={10,25,7,40,15};
 17         int result;
 18         result = largest(a,5);
 19         printf("largest element=%d",result);
 20         return 0;
 21         }
 22
