echo "make lsp && make run-test" >> `cat .git | awk 'NR==1 {print $2; exit}'`/hooks/pre-commit

# chmod 777 ./.git/hooks/pre-commit
