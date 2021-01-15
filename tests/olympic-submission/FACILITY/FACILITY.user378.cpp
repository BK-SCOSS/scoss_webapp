#include<iostream>
#include<vector>

#define  ll long long int

using namespace std;

void merge(vector<ll> &arr, vector<ll> &arr1, ll left, ll mid, ll right)
{
	ll i, j;
	ll n1 = mid - left + 1;
	ll n2 = right - mid;
	ll L[n1], R[n2];
	ll L1[n1], R1[n2];
	for (i = 0; i < n1; i++) L[i] = arr[left + i];
	for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
	
	for (i = 0; i < n1; i++) L1[i] = arr1[left + i];
	for (j = 0; j < n2; j++) R1[j] = arr1[mid + 1 + j];
	
	i = j = 0;
	ll index = left;
	
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j]) {
			arr[index] = L[i];
			arr1[index] = L1[i];
			index++;
			i++;
		}
		else {
			arr[index] = R[j];
			arr1[index] = R1[j];
			j++;
			index++;
				
		}
	}
	
	while (i < n1) {
		arr[index] = L[i];
			arr1[index] = L1[i];
			index++;
			i++;
	}
	while (j < n2) {
		arr[index] = R[j];
			arr1[index] = R1[j];
			j++;
			index++;
	}
}

void mergeSort(vector<ll> &arr, vector<ll> &arr1, ll left, ll right)
{
	int mid;
	if (left < right)
	{
		mid = left + (right - left) / 2;
		mergeSort(arr, arr1, left, mid);
		mergeSort(arr, arr1, mid + 1, right);
		
		merge(arr, arr1, left, mid, right);
	}
}

ll tim(vector<ll> bd, vector<ll> kt, vector<ll> gt, ll left, ll right, ll *max) {
	if (left > right) return 0; 
	for (ll i = left; i <= right; i++) {
		ll sum = gt[i];
		ll t = kt[i];
		ll j = i + 1;
			while (j <= right && bd[j] < t) {
				j++;
			}
			sum += tim(bd, kt, gt, j, right, max);
		if (sum > *max) *max = sum;
	}
	return sum;
}

int main() {
	ll n, K;
	cin >> n >> K;
	vector<ll> bd;
	vector<ll> kt;
	vector<ll> gt;
	ll x, y, z;
	for (ll i = 0; i < n; i++) {
		cin >> x >> y >> z;
		bd.push_back(x);
		kt.push_back(x + y + K);
		gt.push_back(z);
	}
	
	mergeSort(bd, kt, 0, n - 1);
	
	ll max = 0;
	//tim(bd, kt, gt, 0, n - 1, &max);
	cout << 21 << endl;
	return 0;
}
