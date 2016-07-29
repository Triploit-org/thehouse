OBJ = main.o
CC = g++

compile: $(OBJ)
	@echo "[CPP] Link thehouse...    |"
	@$(CC) -fpermissive -o thehouse main.o
	@echo "[CPP] Finished!           |"
	@echo "–––––––––––––––––––––––––––"
	@rm main.o

main.o:
	@echo "–––––––––––––––––––––––––––"
	@echo "[CPP] Compile thehouse... |"
	@$(CC) -fpermissive -c main.cpp
	@echo "[CPP] Finished!           |"
	@echo "–––––––––––––––––––––––––––"

test: compile
	@echo "[MK] Running the Game.... |"
	@echo "==========================="
	@./thehouse
	@echo "==========================="
	@echo "[MK] END                  |"
	@echo "–––––––––––––––––––––––––––"

install: compile
	@echo "[CP] thehouse /bin/       |"
	@sudo cp thehouse /bin/
	@echo [CP] Finished!             |
	@echo "[CP] END                  |"
	@echo "–––––––––––––––––––––––––––"

push: compile
	git add *
	git commit -m "Updated!"
	git push
