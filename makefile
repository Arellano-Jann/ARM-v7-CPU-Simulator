main: main.o Converter.o
	g++ -std=c++11 -g -o $@ $^

clean:
	rm main