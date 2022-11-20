<!doctype html>
<html>
    <head>

        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"
        integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk"
        crossorigin="anonymous">

    </head>
    <body>
        <form action="WebAzure/data/registration.php" method="post">
            <div class="container">
                <h1>Register</h1>
                <p>Please fill in this form to create an account.</p>
                <hr>
                    <label for="name"><b>Your Name</b></label>
                    <input type="text" placeholder="First Name" name="name" value="Mykhailo" required>

                    <label for="surname"><b></b></label>
                    <input type="text" placeholder="Last Name" name="surname" value="Tsaruk">
                <hr>
                    <label for="email"><b>Email</b></label>
                    <input type="text" placeholder="Enter Email" name="email" value="mykhailo.tsaruk@student.tuke.sk" required>
                <hr>
                    <label for="phone-country-"><b>Phone</b></label>
                    <input type="text" placeholder="Phone country '421'" name="phone-country" value="421" maxlength="3">

                    <label for="phone-number"><b>Number</b></label>
                    <input type="text" placeholder="###" name="phone-number1" value="951" maxlength="3">
                    <label for="phone-number"><b> </b></label>
                    <input type="text" placeholder="###" name="phone-number2" value="845" maxlength="3">
                    <label for="phone-number"><b> </b></label>
                    <input type="text" placeholder="###" name="phone-number3" value="413" maxlength="3">
                <hr>
                    <label for="password"><b>Password</b></label>
                    <input type="password" placeholder="Enter Password" name="password" value="qwerty" minlength="6" required>

                    <label for="repeat-password"><b></b></label>
                    <input type="password" placeholder="Repeat Password" name="repeat-password" value="qwerty" required>
                <hr>

                <button type="submit" class="btn btn-primary">Submit</button>
                <button formaction="WebAzure/problem/problem.php" class="btn btn-primary">Problems with registration?</button>
            </div>
            <div>
                <h3>Path to user data file</h3>
                <p><a href="WebAzure/data/data.txt">data.txt</a></p>
                <p><a href="WebAzure/problem/problem.txt">problem.txt</a></p>
<!--                <h4>WebAzure/data/data.txt</h4>-->
<!--                <h4>WebAzure/problem/problem.txt</h4>-->
            </div>
        </form>

    </body>

</html>