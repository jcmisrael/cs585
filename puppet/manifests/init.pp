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
