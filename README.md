# Precursor

```text
⚠️ Precursor is currently in early development. Use with caution
```

Precursor is a C library for rendering pretty console output.

## Goals and assumptions

Precursor will provide:
 - Coloured and styled text in the terminal.
 - Abstractions such as justified text, boxes, rules, and tables.
 - Animated output such as progress bars and loading spinners.
 - A portable library, requiring only C standard library.
 - Default safe behaviour when the terminal capabilities cannot be positively identified.

Precursor will assume:
 - Only a C23 standard library is present.
 - Output is (logically) a monospaced grid of Unicode characters.

## Architecture


### Types

#### Renederables

Renderable objects are high level display objects the user can output, such as styled text, boxes, and tables.

A particular renderable object's implementation is responsible managing how it appears. Renderables produce
_fragments_ for low level use in the output.

#### Fragments

Fragments are low-level output blocks created from _Renderables_, with a uniform _style_ and a position offset.

Terminal or file output is logically a text-stream, so fragments are a single line and cannot contain any newline symbols.

Fragments are produced by _renderables_ breaking themselves into their basic components.

 