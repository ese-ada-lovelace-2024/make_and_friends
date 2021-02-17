import sys
import os

sys.path.insert(0, os.path.abspath(os.sep.join((os.curdir,'..'))))

project = 'Make Lecture'
extensions = ['sphinx.ext.intersphinx',
              'sphinx.ext.autodoc',
              'sphinx.ext.napoleon']
source_suffix = '.rst'
master_doc = 'index'
exclude_patterns = ['_build']
autoclass_content = "both"

import jupyter_sphinx_theme
html_theme = "jupyter"
html_sidebars = {'**': ['sidebartoc.html']}
html_theme_path = jupyter_sphinx_theme.get_html_theme_path()
