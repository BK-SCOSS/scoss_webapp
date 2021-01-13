include<iostrem>
using namespace std;
int main(){

for i:=1 to n do
begin 
L(i):=1;
for j:=1 to i-1 do
if (A[j]<=A[i]) and L(i)<L(j)+1;
end;
}
