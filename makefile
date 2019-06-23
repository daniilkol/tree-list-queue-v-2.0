prog.exe: main.o student.o
	g++ -g main.o student.o -o prog.exe
main.o: main.cpp student.h student_node.h student_queue.h queue_node.h student_list.h
	g++ -g -c main.cpp
student.o: student.cpp student.h
	g++ -g -c student.cpp
clean:
	rm -f main.o student.o prog.exe
