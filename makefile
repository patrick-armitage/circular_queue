TITLE = circularQueue
CPP = Circularqueue.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
