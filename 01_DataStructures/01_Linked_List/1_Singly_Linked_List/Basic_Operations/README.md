# Singly Linked List Implementation in C

An interactive, menu-driven CLI program written in standard C that demonstrates all essential structural operations for standard **Singly Linked Lists**, ensuring bulletproof boundary validations and memory-safe management patterns.

## Author
* **spashokkumar**

## Core Supported Operations
* Dynamic node appending and structured runtime population.
* Safe traversal tracking with formatted visual console outputs.
* Element injection across distinct margins (Head inserts, positional jumps, pre-node relative inserts).
* Safe linear elements checking with standard element positioning analytics.
* Index-safe and boundary-checked removal modules (First index, sequential tail drops, payload value matches, custom positional deletions).
* Dynamic updating of existing node payloads.
* Memory-efficient, in-place pointer reversal ($O(n)$ time complexity, $O(1)$ stack space allocation).
* Total sweeping mechanisms to guarantee zero resource leaks upon system lifecycle exit.

## Bug Resolutions & Maintenance Matrix
The source codebase was audited and refactored to resolve multiple severe operational bugs:
* **Fixed Duplicated Blocks:** Discovered and eliminated conflicting overlapping instances of `deleteAny()`. Split functional pathways distinctly into granular operations: `deleteByValue()` and `deleteByPosition()`.
* **Standardized Environments:** Cleaned dependencies by replacing vendor-locked legacy header inclusions `<malloc.h>` with cross-platform standard libraries `<stdlib.h>`. Corrected signature definitions from `void main()` to the fully compliant runtime signature `int main(void)`.
* **Enforced Null-Pointer Safety Layers:** Applied explicit pre-checks against `start == NULL` limits across insertion, inspection, mutation, and extraction operations to mitigate runtime segmentation faults.
* **Repaired Index Bounds Trailing:** Extended pointer evaluations (`while (tmp != NULL)`) during scanning and search loops to correctly parse final tail elements.
* **Automated Allocation Defers:** Integrated structural exit hooks (`freeAllNodes()`) triggered on program execution end to dynamically reclaim heap configurations cleanly.

## Execution Framework

### Prerequisites
* A standard C compiler (e.g., `gcc`, `clang`, or MSVC Compiler Tools).

### Compilation Pipeline
Compile using default GCC tracking tools via standard terminal loops:
```bash
gcc -Wall -Wextra -std=c99 main.c -o linked_list
```

### Running the Application
Fire up your compiled terminal target output executable:
```bash
./linked_list
```
