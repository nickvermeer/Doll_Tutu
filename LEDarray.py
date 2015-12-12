import cPickle
ledfile=open('LEDPickle.pkl','r')
data=cPickle.load(ledfile)
ledfile.close()
leds=data['Leds']
'''FYI, the led tuple is in the form of 'led strip#','led index','x pos','y pos','distance from heart' '''
for led in leds:
    print('LED(Point({},{}),{},{},{}),'.format(int(led[2]),int(led[3]),int(led[4]),int(led[0]-1),int(led[1])))

for S in range (2,6):    
    for L in range(0,16):
        print('LED(&strips[{}],{}),'.format(S,L))
        
