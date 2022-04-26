# include "header.h"
# include <limits.h>

# define MAX 500

static int enqueue(int *q,int *f, int *r,int size,int x) 
{
	if((*r+1)%size==*f)
	{
		return -1;
		
	}		
    
	*r=(*r+1)%size;
	q[*r]=x;
	if(*f==-1)
		*f=0;
	return 1;
}

static int dequeue(int *q,int *f, int *r,int size) 
{
	int x;
	if(*f==-1)
	{
		return 0;
	}
	x=q[*f];
	if(*f==*r)
	{
	    *f=*r=-1;
	}
	else
	{
	    *f=(*f+1)%size;
	}
	return x;
}

static int qisempty(int f, int r) 
{
     if(f==-1)
       return 1;
     return 0;
}

static unsigned int my_strlen(const char *s) 
{
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}

static void shifttable(const char p[], int t[], int m) 
{
	int i, j ;
	for (i=0;i<MAX;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}

static int horspool(const char src[],const char p[], int n, int m) 
{
	int i,j,k;
    int t[MAX] ;
    shifttable(p, t, m);
	i=m-1;
	while(i<n) 
    {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		   return 1; 
        else
		   i+=t[src[i]];
	}
	return 0;
}

static int DFS(int v,int n, int state[n], connection_t connections[n][n])
{
    int i;
    state[v] = 2;

    for(i=0; i<n; i++)
    {
        if(connections[v][i].distance < INT_MAX && connections[v][i].distance>0)
        {
            if(state[i]==1)
                DFS(i, n, state, connections);
            else if(state[i]==2)
            {
                return 1;
            }
        }
    }
    state[v] = 3;
    return 0 ;
}

static int DF_Traversal(int n, connection_t connections[n][n])
{
    int v;
    int state[n] ;
    for(v=0; v<n; v++)
        state[v] = 1;

    int value = DFS(0, n, state, connections);
    if(value==1) 
    {
        return value ;
    }
    for(v=0; v<n; v++)
    {
        if(state[v]==1)
            value = DFS(v, n, state, connections);
        if(value==1) 
        {
            return value ;
        }
    }
    return 0 ;
}

static int iscycle(int n, const connection_t connnections[n][n]) 
{
    int visited[n] ;
    int i , j;
    connection_t edge ;
    i = n ;
    while(i) {
        for(j=0; j<n; j++) {
            visited[j] = 0 ;
        }
        edge = 
        
        i-- ;
    }
    return 0;
}

static int djikstra(int n, connection_t connnections[n][n], int trip_order[n-1]) 
{
    return -1;
}

static int minKey(int n,int key[], int mstSet[]) 
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

static int min_span_tree(int n,const connection_t connections[n][n],pair_t edges[n - 1]) 
{
    int parent[n];
    int key[n];
    int mstSet[n];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) 
    {
        int u = minKey(n,key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (connections[u][v].time && mstSet[v] == 0 && connections[u][v].time < key[v])
                parent[v] = u, key[v] = connections[u][v].time;
        }
    }

    int sum;
    sum = 0;
    int j=0;
    for (int i = 1; i < n; i++)
    {
        edges[j].first=parent[i];
        edges[j].second=i;
        sum=sum+connections[i][parent[i]].time;
        j++;
    }
    return sum;
}

static void quickSort(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *) )
{
    if(start < end)
    {
        int qIndex = partition(arr, start, end,predicate_func);
        quickSort(arr, start, qIndex-1,predicate_func);
        quickSort(arr, qIndex+1, end,predicate_func);
    }
}

static int len(airport_t airport1,airport_t airport2)
{
    int h=0;
    while(airport1.airport_name[h]!='\0' && airport2.airport_name[h]!='\0' && airport1.airport_name[h] == airport2.airport_name[h])
    {
        h++;
    }
    return h;
}

static void Dijkstra(int n,const connection_t Graph[n][n], int start,int *hash) 
{
  int cost[n][n], distance[n], pred[n];
  int visited[n], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
  { 
      for (j = 0; j < n; j++)
      {
        if (Graph[i][j].time == 0)
            cost[i][j] = INT_MAX;
        else
            cost[i][j] = Graph[i][j].time;
      }
  }


  for (i = 0; i < n; i++) 
  {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) 
  {
    mindistance = INT_MAX;

    for (i = 0; i < n; i++)
    {
      if (distance[i] < mindistance && !visited[i]) 
      {
        mindistance = distance[i];
        nextnode = i;
      }
    }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (mindistance + cost[nextnode][i] < distance[i]) 
            {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
         
            }
        }
    }
    count++;
  }

  for (i = 0; i < n; i++)
  {
        if (i != start) 
        {
        hash[i]  = distance[i];
        }
  }
}



int q1(int n, const connection_t connections[n][n]) 
{
    int is_path = 1;
    int i, j;
    connection_t current_connection ;
    int visited[n] ;
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            visited[j] = 0;
        }
        for(j=0; j<n; ++j) {
            current_connection = connections[i][j] ;
            if (current_connection.distance < INT_MAX) {
                visited[j] = 1;
            }
        }
        for(j=0; j<n; ++j) {
            if(visited[j] == 0)
                is_path = 0;
        }
    }
    
    return is_path;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k, const connection_t connections[n][n]) 
{
    int visited[n] ;
    connection_t current_connection ;
    int w, v, r, f, i ;
    int q[100] ;
    for(i=0; i<n; i++) {
        visited[i] = 0;
    }
    r = f = -1;
    v = src->num_id ;
    visited[src->num_id]=1;
    enqueue(q, &f, &r, 100, v) ;
    while(!qisempty(f, r) && k>0) {
        v = dequeue(q, &f, &r, 100);
        
        for(w=0;w<n;w++) {
            current_connection = connections[v][w] ;
            if((current_connection.distance > 0 )&&(current_connection.distance < INT_MAX)&&(visited[w]==0)) {
                visited[w]=1;
                enqueue(q, &f, &r, 100, w) ;
                if(w == dest->num_id) {
                    return 1 ;
                }
            }
       }
       k-- ;
    }
    return 0 ;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n]) 
{
    int v, w, i, r, f, is_path ;
    int visited[n]  ;
    int q[1000] ;
    connection_t current_connection ;
    is_path = 0;
    r = f = -1;
    v = src->num_id ;
    for(i=0; i<n; i++) 
    {
        visited[i] = 0;
    }
    visited[v]=1;
    enqueue(q, &f, &r, 1000, v) ;
    while(!qisempty(f, r)) 
    {
        v = dequeue(q, &f, &r, 1000);
        
        for(w = 0; w < n; w++) 
        {
            current_connection = connections[v][w] ;
            if((current_connection.distance > 0 )&&(current_connection.distance < INT_MAX)&&(visited[w]==0)) 
            {
                visited[w]=1;
                enqueue(q, &f, &r, 1000, w) ;
            }
            if((current_connection.distance > 0 )&&(current_connection.distance < INT_MAX)&&(visited[w]==1)) 
            {
                if(w == src->num_id) 
                {
                    is_path = 1 ;  // return 1 ;
                }
            }
            
       }
    }
    return is_path;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
    quickSort(airport_list,0,n-1,predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int max = 0;
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            a = len(airports[i],airports[j]);
            if(max < a)
            {
                max = a;
                ans.first = airports[i].num_id;
                ans.second = airports[j].num_id;
            }
        }
    }
    return ans;

}

int q6(int n, int amount, const int entry_fee[n]) 
{
    int left = 0, right = n;
 
    int mid;
    while (left < right) 
    {
        mid = (right + left) >> 1;
        if (entry_fee[mid] == amount) 
        {
            while (mid + 1 < n && entry_fee[mid + 1] == amount)
                mid++;
            break;
        }
        else if (entry_fee[mid] > amount)
            right = mid;
        else
            left = mid + 1;
    }
 
    while (mid > -1 && entry_fee[mid] > amount)
        mid--;
 
    return mid + 1;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n]) 
{
    int s, t, x ;
    for(x =0 ;x < n; x++) 
    {
        s = my_strlen(airports[x].airport_name) ;
        t = my_strlen(pat) ;
        contains[x] = horspool(airports[x].airport_name, pat, s, t) ;
    }
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int trip_num[n][n - 1];
    int a[n - 2], path[n - 1];
    int minlength = INT_MAX, length = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (j < i)
                {
                    trip_num[i][j] = j;
                }
                else
                {
                    trip_num[i][j - 1] = j;
                }
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 2; i++)
        {
            a[i] = trip_num[j][i + 1];
        }
        path[0] = trip_num[j][0];
        jt(a, a, n - 2, n - 2, &length, connections, path);
        if (length < minlength)
        {
            minlength = length;
            for (int l = 0; l < n - 1; l++)
            {
                trip_order[l] = path[l];
            }
        }
    }
    if (minlength == INT_MAX)
        minlength = -1;
    return minlength;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int res = min_span_tree(n,connections,edges);
    return res ;
}

void q10(int n, int k, const airport_t *src,const connection_t connections[n][n], const int destinations[k], int costs[k]) 
{
    int hash[n];
    Dijkstra(n,connections,src->num_id,hash);
    int i=0;
    while(i!=k)
    {
        costs[i] = hash[destinations[i]];
        i++;
    }

}