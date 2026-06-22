funcCpm<-function(n=9,
                    d=c(0,2,6,4,3,5,4,2,0),
                    Suc=list(c(2,3,4),c(5,7),8,6,8,8,9,9,0),
                    Pre=list(0,1,1,1,2,4,2,c(3,5,6),c(7,8)))
                    {
#generates early and late start times of for a cpm network
#Network data:
#n:number of nodes
#d:task duration vector
#Suc:list of successors - zero for none
#Pre:list of predecessors - zero for none
  

#Return vectors early and late 
est<-vector (mode="numeric",length=n)
eft<-vector (mode="numeric",length=n)
lst<-vector (mode="numeric",length=n)
lft<-vector (mode="numeric",length=n)


#Functions
cpmf<-function(s,est){
#find early start and early finish times
  #print(s)
  eft[s]<-est[s]+d[s]
	if ((Suc[[s]][1]!=0)){
		for (i in Suc[[s]]){
            if (est[i] < eft[s]){
             est[i]<-eft[s]
            }
		     est<-cpmf(i,est)
		}	
	} 
	est
	}

cpmb<-function(s,lft){
#find late start and finish times
  lst[s]<-lft[s]-d[s]
  	if (Pre[[s]][1]!=0){
		for (i in Pre[[s]]){
            if (lft[i]>lst[s]){
              lft[i]<-lst[s]                
            }                  
			lft<-cpmb(i,lft)
            }
  	}
  lft
}  
  
#Main
    rf<-cpmf(1,est)                         #call forward step
    lft<-rep(rf[n]+d[n],times=n)            #initialize late finish times
    rb<-cpmb(n,lft)-d                       #call backward step
    slack<-rb-rf                            #slack times 
    r<-list(est=rf,lst=rb,slack=slack)
    r
}
