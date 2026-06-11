library(triangle)
library(igraph)

#
### Exemplo 1 - grafos no igraph
#
#Parameters
Ns=100
n=14
d=c(0,6,5,3,1,6,2,1,4,3,2,3,5,0) #duracao atividades
Suc=list(c(2,3,4),9,c(5,6,7),8,10,12,c(8,11),13,14,12,12,13,14,0) #sucessores
Pre=list(0,1,1,1,3,3,3,c(4,7),2,5,7,c(6,10,11),c(8,12),c(9,13)) #predecessores
edges=c(1,2,1,3,1,4,2,9,3,5,3,6,3,7,4,8,5,10,
        6,12,7,8,7,11,8,13,9,14,10,12,11,12,12,13,13,14)
vals=c(0,-140,318,312,-329,153,193,361,24,33,387,-386,171,0) # elos (arestas)
dMax=44 #duracao maxima
taxa=0.01 #taxa de descont0
g<-make_graph(edges)
tkplot(g,vertex.color='white')


#
### Exemplo 2 - avaliando caminho critico
#

  #1-Dados do grafo de atividades
  d<-c(1,4,5,7,2,3,1)
  elos<-c(1,2,1,3,2,4,3,4,3,5,4,6,5,7,6,7)

  #2-criar grafo e caminhos
  g<-make_graph(elos)
  tkplot(g,vertex.color='white')
  sp<-all_simple_paths(g,from=1,to=7)
  sp
  str(sp)
  l<-length(sp)

  #3-criar vetor com duracao dos caminhos
  dc<-vector(mode="numeric",length=l)
  for(i in 1:l){
    dc[i]<-sum(d[sp[[i]]])
  }
  
  #4-achar o indice do caminho mais longo
  icc<-which.max(dc)
  
  #5-retorna o caminho critico
  cc<-dc[[icc]]
  cc  



#
### Exemplo 3 - Caminho critico com duracoes aleatorias
#

library(igraph)
library(triangle)

#1- Estruturas de dados globais  
n=9
Ns=1000
parDur<-matrix(data=c(0,0,0,
                      1,2,4,
                      2,6,7,
                      3,7,9,
                      2,3,6,
                      3,5,8,
                      2,4,7,
                      1,2,5,
                      0,0,0),ncol=3,byrow = T)

elos<-c(1,2,1,3,1,4,2,5,2,7,3,8,4,6,5,8,6,8,7,9,8,9)
Suc<-list(c(2,3,4),c(5,7),8,
          6,8,8,
          9,9,0)
Pre<-list(0,1,1,
          1,2,4,
          2,c(3,5,6),c(7,8))
durCC<-vector(mode='numeric',length=Ns)
g<-make_graph(elos)
tkplot(g,vertex.color='white')
sp<-all_simple_paths(g,from=1,to=9)
l<-length(sp)

#2-cria amostras das duracoes dos caminhos
dur<-matrix(rep(0,Ns*n),nrow = Ns,ncol=n)
for(j in 1:Ns){
  for(i in 2:(n-1)){
    dur[j,i]<-ceiling(rtriangle(1,parDur[i,1],parDur[i,3],parDur[i,2]))
  }
}

# 3-para cada cenário calcule duracao CC
dc<-vector(mode="numeric",length=l)
for (i in 1:Ns){
  d<-dur[i,]
  for(j in 1:l){
    dc[j]<-sum(d[sp[[j]]])
  }
  icc<-which.max(dc)
  durCC[i] <-dc[icc]  
}

# 4- Analise preliminar 
print(summary(durCC))
hist(durCC)
plot(ecdf(durCC))

