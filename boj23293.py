import sys
input=sys.stdin.readline
logs=[]
ban_player=set()
t,n=map(int,input().split())
players=[{'item':{},'location':1}for _ in[0]*(n+1)]
for _ in[0]*t:
    num,player,code,*codenum=input().split()
    num,player,*codenum=map(int,[num,player]+codenum)
    if code=='M':players[player]["location"]=codenum[0]
    elif code=='F':
        if players[player]['location']!=codenum[0]:
            logs.append(num)
        players[player]['item'][codenum[0]]=players[player]['item'].get(codenum[0],0)+1
    elif code=='C':
        if not players[player]['item'].get(codenum[0],0) or not players[player]['item'].get(codenum[1],0):
            logs.append(num)
        if players[player]['item'].get(codenum[0],0):
            players[player]['item'][codenum[0]]-=1
        if players[player]['item'].get(codenum[1],0):
            players[player]['item'][codenum[1]]-=1
    elif code=="A":
        if players[player]['location']!=players[codenum[0]]['location']:
            logs.append(num)
            ban_player.add(player)
print(len(logs))
if logs:print(*logs)
print(len(ban_player))
if ban_player:print(*sorted(ban_player))