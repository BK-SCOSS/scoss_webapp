from setuptools import setup, find_packages

with open("README.md", mode='r', encoding='utf-8') as fh:
    long_description = fh.read()

setup(name='scoss',
      description='A Source Code Similarity System',
      author='Ngoc Bui',
      long_description=long_description,
      long_description_content_type="text/markdown",
      author_email='ngocjr7@gmail.com',
      version='0.0.1', 
      packages=find_packages(),
      python_requires='>=3.6')
