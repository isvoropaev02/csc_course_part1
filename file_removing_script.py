from os import listdir, walk, scandir, remove

path = "C:\\Users\\isvoropaev\\Desktop\\c++\\csc_course_part1"


def list_directory(path=path):
    for name in listdir(path):
        print(name)


def walk_directory(path=path):
    for root, dirs, files in walk(path, topdown=True):
        print(root)
        print(dirs)
        print(files)
        print('--------------------------------')


def scan_directory(path=path):
    with scandir(path) as it:
        for entry in it:
            print(entry.name)


def filemap(path, action, is_target):
    with scandir(path) as it:
        for entry in it:
            if entry.is_dir():
                filemap(entry.path, action, is_target)
            elif is_target(entry):
                action(entry)

# пример использования
# filemap(path,
#          lambda e: print(e.name),
#          lambda e: e.name.lower().endswith(".py"))


class CountFile:
    def __init__(self):
        self.__count = 0
    @property
    def count(self):
        return self.__count
    def __call__(self, entry):
        self.__count += 1
    def __str__(self):
        return F"{self.__count}"
# Использование этого счетчика
c = CountFile()
# filemap(path,
#          c,
#          lambda e : e.name.lower().endswith( ".cpp" ))
# print(c)


def endswith(*args):
    extensions = [ext.lower() for ext in args]
    def _is_target(entry):
        name = entry.name.lower()
        for ext in extensions:
            if name.endswith(ext):
                return True
        return False
    return _is_target

# пример использования
def remove_files_with_format(format=".exe", path=path):
    files_list = []

    filemap(path,
            lambda e: files_list.append(e.name),
            endswith(format))

    for file_name in files_list:
        remove(path + "\\" + file_name)


remove_files_with_format(format='.exe')
