<?php

require_once__DIR__.'/WebAzure/data.php';
require_once__DIR__.'/WebAzure/registration.php';

?>
<!doctype html>
<html>
    <head>

        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css" 
        integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" 
        crossorigin="anonymous">

    </head>
    <body>

    <div class="container">
        <div class="row">
            <div class="col-md-6 offset-md-3">
                <form method="post">
                    <div class="form-group">
                        <label for="name">Name</label>
                        <input type="name" class="form-control" id="name">
                    </div>
                    <div>
                        <label for="surname">Surname</label>
                        <input type="surname" class="form-control" id="surname">
                    </div>
                    <div class="form-group">
                        <label for="email">E-mail</label>
                        <input type="email" class="form-control" id="email">
                    </div>
                    <div class="form-group">
                        <label for="phone">Phone number</label>
                        <input type="phone" class="form-control" id="phone">
                    </div>
                    <div class="form-group">
                        <label for="password">Password</label>
                        <input type="password" class="form-control" id="Password">
                        <label for="repear_password"></label>
                        <input type="repear_password" class="form-control" id="repear_password">
                    </div>
                </form>
            </div>
        </div>
    </div>

    </body>
</html>