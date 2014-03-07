# Islandora LOCKSS-O-Matic

A module that allows and Islandora instance to deposit content into a Private LOCKSS Network managed by [LOCKSS-O-Matic](https://github.com/mjordan/lockss-o-matic).

Using a simple implementation of the [SWORD](http://swordapp.org/) protocol, this module notifies LOCKSS-O-Matic that new content is available to have harvested into a [Private LOCKSS Network](http://www.lockss.org/community/networks/). Currently only content that is packaged using the [BagIt](https://wiki.ucop.edu/display/Curation/BagIt) specification can be deposited.

Only new or modified Bags are deposited.

## Creating deposits

Deposits can be either 'In progress' or 'closed'.

In progress deposits are made over time and automatically. On each cron run, this module checks to see if any new Bags have been created and if so, issues the deposit request against LOCKSS-O-Matic for the new Bags. LOCKSS-O-Matic determines which LOCKSS Archival Units to add them to. Using in-progress deposits is suitable when you want every Bag to be deposited automatically, over time.

Closed deposits are created with Drush command accompanying this module:

```drush create-islandora-lom-deposit "New Islandora objects 2014-06"```

or its short form

```drush lomdep "New Islandora objects 2014-06"```

Using closed deposits is suitable when you have just created a set of Bags (in a batch, for example), and you want those Bags to be deposited in a single LOCKSS Archival Unit.

## Status of this module

Still under development, mainly as a vehicle to help test LOCKSS-O-Matic. However, it will be developed to production status.

## Author/maintainer

Mark Jordan mjordan - sfu dot ca

## License

Islandora BagIt is released under the GNU GENERAL PUBLIC LICENSE, version 3. See LICENSE.txt for more information.
