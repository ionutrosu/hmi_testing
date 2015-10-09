# /usr/bin/perl -w

exec('git log master --name-only --pretty=format:"-hv- %h ; %an; %ae; %ai ; %s" > ./doc/temp.csv');

__END__