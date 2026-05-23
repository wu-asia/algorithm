
L是20,15,17,18,9,6,8
void pro(seqlist* L)
{
	pos=0;
	for(int i = 0; i <= L->last; i++)
	{
		if(L->elem[i]%2==0)
		{
			if(i!=pos)
			{
				swap(L->elem[i], L->elem[pos]);
			}
		}
		pos++;
	}
}

已知带头结点的单链表L中的元素是整数，若有一个单链表L的元素是（5，2，6，4，8），
经过下列的运算
void proc(LiskList l)
{
	if(l->next==NULL) return;
	pivot-l->next;
	pre=pivot;
	p=pivot->next;
	while(p)
	{
		q=p->next;
		if(p->data=pivot->data)
		{
			pre=p;
			p=q;
		}
		else
		{
			pre->next = p->next;
			p->next = l->next;
			l->next = p;
			p = q;
		}
	}
}


void proc(liklist l)
{
	if(l->next == NULL) return;
	piv = l->next;
	pre = piv;
	p = piv->next;
	while(p)
	{
		q = p->next;
		if(p->data >= piv->data)
		{
			pre = p;
			p = q;
		}
		else
		{
			pre->next = p->next;
			p->next = l->next;
			l->next = p;
			p = q;
		}
	}
}

已知顺序表的元素为整数，顺序表的类型如下：
#define MaxSize 100
typedef struc
{
	int elem[MaxSize + 1];
	//下标为零空闲
	int len;
}Seqlist;

若顺序表L中的元素是(46, 55, 18, 42, 94, 17, 11, 70)
数组d中的元素是(4, 2, 1)
经过如下的操作prc(&L, d, 3)

void shinert(Seqlist* l, int dk)
{
	for(i = 1 + dk; i <= l->len; i++)
		if(l->elem[i] < l->elem[i - dk])
		{
			l->elem[0]=l->elem[i];
			for(j=i -dk;j > 0 && l->elem[0] < l->elem[j];j = j-dk)
				l->elem[j + dk] = l->elem[0];jl->elem[j+dk] = l->elem[0];
		}
}

void proc(Seqlist* l, int d[], int m)
{
	for(k=0;k <m;i++)
		shinerst(l, d[k]);
}

void proc(linklist l, linklist la, linklist lb, linklist lc)
{
	node *p, *pa, *pb, *pc, *tmp;
	pa = la;
	pb=lb;pc=lc;
	while(p)
	{
		tmp=p->next;
		if(p->data >= 'a' && p->data<='z'|| p->data>='A' && p->data<='Z')
		{
			pa->next;
			pb=p;
		}
		else if(isdigit(p->data))
		{
			pb->next=p;
			pb=p;
		}
		else
		{
			pc->next = p;
			pc= p;
		}
		p = tmp;
	}
	l->next=NULL;
	pa->next = la;
	pb->next=lb;
	pc->next=lc;
}

(2, 3, 7, 8, 9, 6)
void proc(linklist l)
{
	node *p, *tmp;
	if(!l->next || !(l->next->next)) return;
	p=l->next->next; l->next->next = NULL;
	while(p)
	{
		tmp=p->next;
		p->next = l->next;
		l->next = p;
		p = tmp;
	}
}

void proc(seqlist*l)
{
	int i, j, min;
	for(i=0; i < l->last;i++)
	{
		min = i;
		for(j=i+1;j<=l->last;j++)
			if(l->elem[j]<l->elem[min]) min=j;
		if(min!=i)
			swap(l->elem[min],l->elem[i]);
	}
}

void proc(linklist l)
{
	for(p=l->next; p->next;p=p)
}