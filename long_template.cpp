//Day la template Tung hay dung
//Tung chi ,muon noi la Tung yeu ban rat nhieu
//Copy thi nho xoa nha
//Love KKL
#include<bits/stdc++.h>

using namespace std;

/*** Optimization ***/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

/*** Typedef ***/
typedef long long ll;
typedef unsigned long long ull;

/*** Input Output***/
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define sc3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

/*** #define pf1(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)***/

/*** Loops ***/
#define for0(num) for(ll i = 0; i < num; i++)
#define for1(num) for(ll i = 1; i <= num; i++)
#define forr(num) for(ll i = num - 1; i >= 0; i--)
#define forin(arr, num) for(ll i = 0; i < num; i++) sc1(arr[i]);
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');

/*** Define Values ***/

#define mod 1000000007
#define PI acos(-1.0)
#define eps 1e-7
#define size1 1000010
//#define INF 1e15
//#define int long long

#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define REP(i,a,b)        for(int i=a;i<b;i++)

#define CLR(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll


#define pb push_back
#define in insert
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define lb lower_bound
#define ub upper_bound
/*** STLs ***/
typedef vector<int> vi;
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;


/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
inline bool cmp(pll a,pll b){ if(a.ff == b.ff) return a.ss < b.ss; return a.ff < b.ff; }

/*** BitWise Operations
bool getBit (ll num, ll pos) { return num & (1 << pos); } // get bit right -> left
ll setBit (ll num, ll pos) { return num | (1 << pos); }
ll chearBit (ll num, ll pos) { ll mask = ~(1 << pos); return num & mask; }
ll updateBit (ll num, ll pos, bool bit1or0) { ll value = bit1or0 ? 1 : 0; ll mask = ~(1 << pos); return (num & mask) | (value << pos); }
 ***/

/*** Grids ***/
int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };

 /*** Some Prints ***/
#define en cout << '\n';
#define no cout << "NO" << '\n';
#define yes cout << "YES" << '\n';
#define case cout << "Case " << t++ << ": ";
#define one cout << "-1"<<'\n';
#define ret return 0;

/*** Functions***/
ll binpow(ll a, ll b, ll m) {a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;}return res;}
ll InverseMod(ll base, ll pow) { if(pow == 0) return 1; ll ans = InverseMod(base, pow / 2); ans = (ans * ans) % mod; if(pow & 1){ return (ans * base) % mod; } else{ return ans; } }
bool isprime(ll num) { if(num < 2) return false; for(ll i = 2; i * i <= num; i++){ if(num % i == 0) return false; } return true; }
ll EularPHI(ll num) { double ans = num; for(ll i = 2; i * i <= num; i++){ if(num % i == 0){ while (num % i == 0) { num /= i; } ans *= (1.0 - (1.0 / (double)i)); } } if(num > 1) ans *= (1.0 - (1.0 / (double)num)); return (ll)ans; }

template <class T> inline T gcd(T a,T b){if(b == 0)return a; return gcd(b, a % b);}
template <class T> inline T lcm(T a,T b){return a * b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll ans = 1;while(p--) ans *= b; return ans;}

ll mul(ll a,ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a,ll b) {
    return (a % mod + b % mod) % mod;
}

ll powm(ll a, ll b) {

    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

ll divide(ll a,ll b) {
    return (a % mod) * powm(b, mod - 2) % mod;
}

bool vectorSortedOrNot(vector<int> v, int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (v[n - 1 ] < v[n - 2])
        return 0;

    return vectorSortedOrNot(v, n - 1);
}

int sumDigits(int num)
{
    return num == 0 ? 0 : num % 10 + sumDigits(num / 10);
}

ll countDigits(ll n)
{
    return (ll)log10(n)+1;
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

#ifndef ONLINE_JUDGE
    printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
   return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do something instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
/*
? Some basic stuff

        ? Sets : Unique element container.
            ! set<int,greater<int> > s; // to order the set in descending order
            * To check if an element is in a set : s.count(x)
            ! Another method to check if an element exists in a set :if(s.find(x)!=s.end()){ // condition  }
            * Value of First Element of Set : *(s.begin())
            * Value of Last Element of Set : *(--s.end())
            ! To erase an element by value: s.erase(x);
            * begin() - returns an iterator to first element of set. The value of the element can be accessed using *(s.begin())
            * end() - Returns an iterator to the theoretical element that follows last element in the set.
            * size() - Returns the number of elements in the set.
            * max_size() - Returns the maximum number of elements that the set can hold.
            * empty() - Returns whether the set is empty.
            ! find(x) - Returns an iterator to the element ‘x’ in the set if found, else returns the iterator to end.
            * erase(x)– Removes the value ‘x’ from the set. It erases an element by value
            * count(x) - Returns 1 or 0 based on the element ‘x’ is present in the set or not. It's the best way to check for the presence of an element.
            * lower_bound(x) – Returns an iterator to the first element that is equivalent to ‘x’ or definitely will not go before the element ‘x’ in the set.
              lower_bound can also be thought as the smallest element greater than or equal to x
            * Return reverse iterator to reverse beginning: (s.rbegin())
            * Set to be sorted in decreasing order: set<int, greater<int> >
            * emplace() : If the function successfully inserts the element (because no
                    equivalent element existed already in the set), the function returns a
                    pair of an iterator to the newly inserted element and a value of true.
            * const bool is_in = s.find(x) != s.end(); check if an element is in the set.
            ! myset.erase(x) #directly by value. logarithmic complexity
            ! myset.erase(iteratortoanelement,s.end())
            * for_each(all(s),do_something);
            ! set<int> :: iterator it = myset.find(60);

        ? Vectors
            @ Erase elemnents by value rather than position
            # vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
            *
            @ Erase duplicates in a sorted array
            # v.erase(unique(v.begin(), v.end()), v.end());
            *
            @ Erase elements by position
            # vec.erase(vec.begin() + 1);
            vector<int> v; v.resize(n,0); // resizes the vector and initializes it too.
            front(), back(), push_back(), pop_back()
            * begin() - Returns an iterator pointing to the first element in the vector
            * end() - Returns an iterator pointing to the theoretical element that follows the last element in the vector
            * rbegin() - Returns a reverse iterator pointing to the last element in the vector (reverse beginning).
            * rend() - Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
            * cbegin(),cend(),crbegin(),crend()
            * size() - Returns the number of elements in the vector.
            * max_size() -  Returns the maximum number of elements that the vector can hold.
            * capacity() - Returns the size of the storage space currently allocated to the vector expressed as number of elements.
            * resize() - Resizes the container so that it contains ‘n’ elements.
            * empty() - Returns whether the container is empty.
            * shrink_to_fit() - Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
            * reserve() - Requests that the vector capacity be at least enough to contain n elements.
            * [i] - Returns a reference to the element at position ‘i’ in the vector
            * at(i) - Returns a reference to the element at position ‘i’ in the vector
            # front() - Returns a reference to the first element in the vector
            # back() - Returns a reference to the last element in the vector
            * data() - Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
            * assign() - It assigns new value to the vector elements by replacing old ones
            * push_back() - It push the elements into a vector from the back
            # pop_back() - It is used to pop or remove elements from a vector from the back.
            ! insert() - It inserts new elements before the element at the specified position
            * erase() - It is used to remove elements from a container from the specified position or range
            * swap() - It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
            * clear() - It is used to remove all the elements of the vector container
            * emplace() - It extends the container by inserting new element at position
            * emplace_back() - It is used to insert a new element into the vector container, the new element is added to the end of the vector
            # for (auto it = myvector.begin(); it != myvector.end(); ++it)  // normal iterator
            # for (auto t:v)

        ? Queue
            * empty() - Returns whether the queue is empty.
            * size() - Returns the size of the queue.
            * emplace() - Insert a new element into the queue container, the new element is added to the end of the queue.
            * front() - front() function returns a reference to the first element of the queue.
            * back() - returns a reference to the last element of the queue.
            * push(x) - adds the element ‘x’ at the end of the queue
            * pop() - deletes the first element of the queue

        ? Priority_Queue
            ! priority_queue <int, vector<int>, greater<int>> pq; // to make a priority queue in descending order
            * empty() - returns whether the queue is empty.
            * size() -  returns the size of the queue.
            # top() -  Returns a reference to the top most element of the queue
            * push(x) - adds the element ‘x’ at the end of the queue.
            * pop() -  deletes the first element of the queue.
            * swap() -  swap the contents of one priority queue with another priority queue of same type and size.
            * emplace() - insert a new element into the priority queue container, the new element is added to the top of the priority queue.

        ? Deque
            Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
            They are similar to vectors, but are more efficient in case of insertion and deletion of elements.
            Unlike vectors, contiguous storage allocation may not be guaranteed.
            * insert()
            * rbegin()
            * rend()
            * assign()
            * resize()
            * push_front()
            * push_back()
            * pop_front()
            * pop_back()
            * front()
            * back()
*/
