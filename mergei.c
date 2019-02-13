#include<stdio.h>
struct Interval {
	int start;
	int end;
};
typedef struct Interval interval;
int findStartIndex(interval *intervals,int sz,int nstart,int *iflag)
{
	int i;
	for(i=0;i<sz;i++)
	{
		if(nstart>intervals[i].end)
			continue;
		else
		{
			if(nstart>intervals[i].start)
				return i;
			else
			{
				*iflag=1;
				return i;
			}

		}
	}
	return -1;
}

int findEndIndex(interval *intervals,int sz,int nend,int istart,int *eflag)
{
	int i;
	for(i=istart;i<sz;i++)
	{
		if(nend>intervals[i].end)
			continue;
		else
		{
			if(nend>intervals[i].start)
				return i;
			else
			{
				*eflag=1;
				if(i-1<0)
					return 0;
				else
					return i-1;
			}
		}
	}
}

interval* insert(interval *intervals,int sz,interval newInterval,int *len)
{
	int i,j,istart,ival,iend,eflag,iflag,nstart,nend;
	printf("\ninside func\n");
	for(i=0;i<sz;i++)
    	{
        	printf("%d\t%d\n",intervals[i].start,intervals[i].end);
    	}	
	printf("\nAfter printf");
	printf("new interval %d\t%d\n",newInterval.start,newInterval.end);
	ival=0;
	nstart=newInterval.start;
	nend=newInterval.end;
	iflag=0;
	istart=findStartIndex(intervals,sz,nstart,&iflag);
	eflag=0;
	iend=findEndIndex(intervals,sz,nend,istart,&eflag);
	if(iflag==1 && eflag==1)
	{
		 intervals[istart].start=nstart;
		intervals[iend].end=nend;
		*len=sz;
	}
	else
	{
		if(iflag==1)
        	{
                	intervals[istart].start=nstart;
			*len=sz;
        	}
		else if(eflag==1)
		{
			intervals[iend].end=nend;
			*len=sz;
		}
		else
		{
			if(istart!=iend)
			{
				intervals[istart].end=intervals[iend].end;
				j=iend+1;
				for(i=istart+1;i<sz && j<sz ;i++,j++)
				{
					intervals[i].start=intervals[j].start;
					intervals[i].end=intervals[j].end;
				}
				*len=sz-(iend-istart);
			}
		}
	}	
	
	return intervals;
}
void main()
{
	int len,i,sz;
	//interval *newIntervals;
	interval *intervals;
	interval newInterval;
	printf("\nEnter size\n");
	scanf("%d",&sz);
	intervals=(interval*)malloc(sz*sizeof(interval));
	printf("\nEnter each interval\n");
	for(i=0;i<sz;i++)
	{
		scanf("%d %d",&intervals[i].start,&intervals[i].end);
	}
	printf("\n after scanning\n");
	printf("\nEntern new interval\n");
	scanf("%d %d",&newInterval.start,&newInterval.end);
	intervals=insert(intervals,sz,newInterval,&len);
	printf("\nOutput interval is\n");
	for(i=0;i<len;i++)
        {
                printf("%d\t%d\n",intervals[i].start,intervals[i].end);
        }
}
