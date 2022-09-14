#!/usr/bin/env python3
import argparse
import os

from mako.template import Template


INDEX_TEMPLATE = r"""---
title: ${dirname}
---
<h2>Index of ${dirname}</h2>
<table>
    <tbody>
        <tr>
            <th>&nbsp;</th>
            <th>Name</th>
            <th>Size</th>
        </tr>
        % for name in dirnames:
        <tr>
            <td><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAd5JREFUeNqMU79rFUEQ/vbuodFEEkzAImBpkUabFP4ldpaJhZXYm/RiZWsv/hkWFglBUyTIgyAIIfgIRjHv3r39MePM7N3LcbxAFvZ2b2bn22/mm3XMjF+HL3YW7q28YSIw8mBKoBihhhgCsoORot9d3/ywg3YowMXwNde/PzGnk2vn6PitrT+/PGeNaecg4+qNY3D43vy16A5wDDd4Aqg/ngmrjl/GoN0U5V1QquHQG3q+TPDVhVwyBffcmQGJmSVfyZk7R3SngI4JKfwDJ2+05zIg8gbiereTZRHhJ5KCMOwDFLjhoBTn2g0ghagfKeIYJDPFyibJVBtTREwq60SpYvh5++PpwatHsxSm9QRLSQpEVSd7/TYJUb49TX7gztpjjEffnoVw66+Ytovs14Yp7HaKmUXeX9rKUoMoLNW3srqI5fWn8JejrVkK0QcrkFLOgS39yoKUQe292WJ1guUHG8K2o8K00oO1BTvXoW4yasclUTgZYJY9aFNfAThX5CZRmczAV52oAPoupHhWRIUUAOoyUIlYVaAa/VbLbyiZUiyFbjQFNwiZQSGl4IDy9sO5Wrty0QLKhdZPxmgGcDo8ejn+c/6eiK9poz15Kw7Dr/vN/z6W7q++091/AQYA5mZ8GYJ9K0AAAAAASUVORK5CYII="
                alt="[DIR]"></td>
            <td><a href="${name}">${name}</a></td>
            <td>&nbsp;</td>
        </tr>
        % endfor
        % for name in filenames:
        <tr>
            <td><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAIAAACQkWg2AAAABnRSTlMAAAAAAABupgeRAAABHUlEQVR42o2RMW7DIBiF3498iHRJD5JKHurL+CRVBp+i2T16tTynF2gO0KSb5ZrBBl4HHDBuK/WXACH4eO9/CAAAbdvijzLGNE1TVZXfZuHg6XCAQESAZXbOKaXO57eiKG6ft9PrKQIkCQqFoIiQFBGlFIB5nvM8t9aOX2Nd18oDzjnPgCDpn/BH4zh2XZdlWVmWiUK4IgCBoFMUz9eP6zRN75cLgEQhcmTQIbl72O0f9865qLAAsURAAgKBJKEtgLXWvyjLuFsThCSstb8rBCaAQhDYWgIZ7myM+TUBjDHrHlZcbMYYk34cN0YSLcgS+wL0fe9TXDMbY33fR2AYBvyQ8L0Gk8MwREBrTfKe4TpTzwhArXWi8HI84h/1DfwI5mhxJamFAAAAAElFTkSuQmCC"
                alt="[DIR]"></td>
            <td><a href="${name}">${name}</a></td>
            <td>${getsize(join(root, name))}</td>
        </tr>
        % endfor
    </tbody>
</table>
"""


def getsize(path):
    size = os.path.getsize(path)
    if size < 1024:
        return f"{size} B"
    if size < 1048576:
        return f"{size / 1024.:.2f} KB"
    return f"{size / 1048576.:.2f} MB"


def build_index(directory):
    for root, dirs, files in os.walk(directory):
        filename = os.path.join(root, "index.html")
        with open(filename, "w") as fp:
            fp.write(
                Template(INDEX_TEMPLATE).render(
                    dirname=os.path.basename(os.path.abspath(root)),
                    dirnames=sorted(dirs),
                    filenames=sorted(x for x in files if x != "index.html"),
                    getsize=getsize,
                    join=os.path.join,
                    root=root,
                )
            )
        print(f"Wrote {filename}")


def main():
    for directory in [
        "public",
        "cs24_f13/code",
        "cs24_f13/examples",
        "cs24_f13/slides",
        "cs24_m13/code",
        "cs24_m13/slides",
        "cs32_m12/code",
        "cs32_m12/slides",
    ]:
        build_index(directory)


if __name__ == "__main__":
    main()
