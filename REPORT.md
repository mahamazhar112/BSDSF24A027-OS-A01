# REPORT.md

## Feature 2: Multi-file Project using Make Utility

**Q1: Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?**

This rule tells `make` that `$(TARGET)` (the final executable) depends on all the object files listed in `$(OBJECTS)`. When any `.o` file changes, `make` re-links the target. The actual command, `$(CC) $(OBJS) -o $@`, simply passes every object file directly to the compiler/linker, which combines them into one executable. This differs from a rule that links against a library, where the command instead uses `-L<path> -l<name>` flags (e.g. `$(CC) $(MAIN_OBJ) -L../lib -lmyutils -o $@`). In that case the linker does not receive every `.o` file directly; it searches the given library path for a library file and pulls in only the symbols it actually needs from it. Linking directly against object files couples the build to every source file explicitly, while linking against a library hides that detail behind a single packaged unit.

**Q2: What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**

A git tag is a named pointer to a specific commit, usually used to mark a stable or released version of the project (e.g. `v0.1.1-multifile`). It is useful because it lets you return to or reference an exact point in history by a meaningful name instead of a commit hash, which is especially helpful when creating releases. A simple (lightweight) tag is just a pointer to a commit with no extra information, similar to a branch that doesn't move. An annotated tag, created with `git tag -a`, is a full object in git's database: it stores the tagger's name and email, the date, and a message, and it can be signed. Annotated tags are recommended for releases because they carry this extra metadata and history.

**Q3: What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**

A GitHub Release marks a specific tagged commit as an official, distributable version of the project, with a title, description of what changed, and any downloadable assets. It gives users and collaborators a clear, versioned snapshot of the project's history instead of having to browse commits or tags manually. Attaching binaries (such as the compiled `bin/client` executable) is significant because it lets someone download and run the program immediately without needing to clone the repository, install a compiler, and build it themselves. This is especially useful for end users who just want to use the software rather than develop it.


## Feature 3: Creating and using Static Library

**Q1: Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?**

Part 2's Makefile only had `TARGET`, `SRCS`, and `OBJS`, and a single rule that linked every object file directly into one executable. Part 3 adds `LIBNAME`, `STATIC` (the `.a` path), `LIB_OBJS` (object files that belong in the library, excluding `main.o`), `MAIN_OBJ`, and `TARGET_STATIC`. It also adds two new rules: one that archives `LIB_OBJS` into `$(STATIC)` using `ar`, and one that links only `MAIN_OBJ` against that library using `-L../lib -lmyutils` instead of listing every object file. The key difference is that the library groups the reusable functions into one archive, and the final executable is built by linking against that archive rather than against each object file individually.

**Q2: What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?**

`ar` (archiver) bundles multiple object files into a single archive file (a static library, `.a`), which the linker can later search through. The `rcs` flags used here mean: `r` (insert/replace the files in the archive), `c` (create the archive if it doesn't exist), and `s` (write an index/symbol table into the archive). `ranlib` generates or refreshes that same symbol index for an existing archive, which lets the linker quickly find which object file in the archive defines a given symbol. Since the `s` flag already tells `ar` to build that index at creation time, `ranlib` isn't strictly required in this Makefile; it's mainly needed if the archive was created without `s` or was modified afterward without regenerating the index.

**Q3: When you run `nm` on your `client_static` executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?**

Yes, running `nm bin/client_static` shows `mystrlen` (and the other library functions) with type `T`, meaning they are defined and present in the text (code) section of the executable itself. This confirms that static linking copies the actual machine code of the functions the program uses from the library archive directly into the final executable at link time, rather than referencing an external file. As a result, the executable is self-contained and larger, and it no longer needs `libmyutils.a` to run.