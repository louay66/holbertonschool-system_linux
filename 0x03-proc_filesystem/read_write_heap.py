#!/usr/bin/python3
"""progrram that read file binarry mem
    and find in memory heap the second argument
    and swap it with the third argument
    """

from sys import argv


def rw_file_mem(pid, prev, new):
    """read file binarry mem and
    file maps and raplace arg2 with arg3"""

    maps = "/proc/{}/maps".format(pid)
    mem = "/proc/{}/mem".format(pid)
    with open(maps, "r") as maps, open(mem, "rb+") as mem:
        for l in maps:
            if l.find("[heap]") != -1:
                section = l.split(" ")
                adrss = section[0].split("-")
                start = int(adrss[0], 16)
                end = int(adrss[1], 16)
                perm = section[1]
                break
        if perm[:2] != "rw":
            raise PermissionError
        mem.seek(start)
        buff = mem.read(end - start)
        idx = buff.index(bytes(prev, "ASCII"))
        mem.seek(start + idx)
        mem.write(bytes(new + "\0", "ASCII"))
        maps.close()
        mem.close()


def main():
    """ main function"""
    try:
        exit_code = 1
        if len(argv) != 4:
            raise ValueError('Usage: read_write_heap.py'
                             ' pid search_string replace_string')
        if len(argv[3]) > len(argv[2]):
            raise IndexError
        rw_file_mem(int(argv[1]), argv[2], argv[3])
        exit_code = 0
    except Exception as a:
        print(a)
    finally:
        if (exit_code == 0):
            print("[*] maps: /proc/{}/maps".format(argv[1]))
            print("[*] mem: /proc/{}/mem".format(argv[1]))
            print("[*] Found \"{}\"".format(argv[2]))
            print("[*] Replaced it with \"{}\"".format(argv[3]))
        exit(exit_code)


if __name__ == '__main__':
    main()
