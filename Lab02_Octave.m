pkg load control %Careega o pacote
vT = 150
Ia = 10
Ra = 1
La = 0.05
n = 1800
Jm = 0.5

Kce = Kt =  ((vT - (Ra * Ia)) / (n*(pi/30)))

A = [ (-Ra/La) (-Kce/La) ; (Kt/Jm) 0]
B = [(1/La) ; 0]
C = [0 (30/pi)]
D = [0]

EE = ss(A,B,C,D)

step (EE)


G = tf(EE)
step(G)

