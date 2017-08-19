## Problem 
## Solution 
可以观察到，如果一个'O'没有被'X'包围，那么它一定是和边界上的'O'连通的。因此我们可以使用连通性来解决这个问题。连通性问题的求解可以使用union find这种数据结构。

### 1. Union Find
对于连通的所有节点，我们可以认为他们属于同一个组，不连通的节点必然不属于同一个组。所以，对于两个节点，我们可以通过判断他们所属的组号是否相同来判断是否连通。
用一个数组来表示这层关系，index是节点的整数表示，而相应的值就是该节点的组号了。

```c++
class UF() {
    UF(int N); // constructor
    ~UF();     //Deconstructor
    int find(int p);   //当前节点p的组号
    void union(int p, int q);   //连接节点p和节点q
    bool connected(int p, int q); //判断两节点是否连通
    int count();     //不同的组数
}
```


**1) Quick Find算法**
```c++
class UF() {
private:
    int[] id;
    int count;
public:
    UF(int N) {
        count = N;
        id = new int[N];
        for (int i=0; i<N; i++)
            id[i] = i;
    }

    int count() {
        return count;
    }

    int find(int p) {
        return id[p];
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void union(int p, int q) {
        // 获取组号
        int pId = find(p);
        int qId = find(q);
        // 如果组号相等，直接返回
        if (pId == qId) return;
        //
        int n = sizeof(id)/sizeof(int);
        for (int i=0; i<n; i++) {
            if (id[i] == pId)   //合并两组，pId的组号改为qId
                id[i] = qId;
        }
        count--;

    }

}
```

这种算法在find时是非常高效的，可以直接根据index查出相应的组号，但是在union时，需要遍历整个数组，找到需要修改的节点并修改组号。这样，每次需要添加新路径时就需要线性的复杂度。如果需要添加的路径数量是M，节点数量是N，那么时间复杂度就是MN，显然这是一个平方阶的复杂度。

**2) Quick Union算法**
上述解法中，由于每个节点所属的组号都是单独记录的，因此需要修改时，只能通过遍历逐一修改。因此，我们需要寻找方法将节点更好的组织起来。我们可以使用树的结构，id[p]中存储的是当前节点的父节点的序号，如果p是根节点的话，id[p]=p。这样经过若干次查找，总能找到它的根节点。

在连接两个节点时，首先找到他们各自的根节点，如果根节点不同，就将一个根节点的父节点设为另一个根节点，相当于将一个树作为另一棵树的一个子树。
```c++
int find(int p) {
    while (id[p] != p) p = id[p];
    return p;
}

void union(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) return;
    id[pRoot] = qRoot;  //将pRoot接到qRoot上，作为qRoot的一棵子树
    count--;
}
```

但是这样还会出现一个问题，树这种数据结构容易出现极端情况，因为在建树过程中，树的最终形态严重依赖输入数据本省的特性，比如数据是否排序，是否随机分布等。

现在的做法是id[pRoot] = qRoot，即任何情况下都将qRoot作为根节点，pRoot接到qRoot上。这样显然是不合理的，比如p的规模比q的规模要大很多时，p和q结合之后树就会变得非常不平衡。所以我们应该考虑树的大小，将小的树接到大树中。
```c++
UF(int N) {
    id = new int[N];
    sz = new int[N];   //新增一个数组sz，记录各个组的大小
    for (int i=0; i<N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

}

void union(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) return;
    //将小树作为大树的子树
    if (sz[pRoot] > sz[qRoot]) {
        id[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }
    else {
        id[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    }
    count--;
}
```


**改进**
节点组织的最理想情况是一棵非常扁平的树，所有子节点都应该在高度为1的地方。如果我们在while循环的过程中保存所有路过的节点到一个数组中，然后在while循环结束后把所有路过节点的父节点都设为根节点，就可以把树变为一棵扁平的树了。但是这样会造成频繁的生成中间节点数组，相应的分配销毁的时间自然上升。

另外，我们可以在find时将节点的父节点指向该节点的爷爷节点，这样就可以压缩路径，使find操作更加高效。
```c++
int find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]];  //父节点设为它的爷爷节点
        p = id[p];
    }
}
```