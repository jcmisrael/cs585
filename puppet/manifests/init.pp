exec { 'apt-get update':
  path => '/usr/bin',
}

package { 'build-essential':
  ensure => present,
  require => Exec['apt-get update'],
}

package { 'cmake':
  ensure => present,
  require => Exec['apt-get update'],
}

package { 'libgtest-dev':
  ensure => present,
  require => Exec['apt-get update'],
}

exec { 'build-gtest':
  command => 'cmake . && make && mv libgtest* /usr/local/lib/',
  cwd => '/usr/src/gtest',
  require => Package['libgtest-dev'],
  creates => ['/usr/local/lib/libgtest.a','/usr/local/lib/libgtest_main.a'],
  path => ['/usr/bin','/usr/sbin','/bin'],
}
